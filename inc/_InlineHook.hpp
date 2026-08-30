/*
Copyright (C) 2012-2014 LINK/2012 <dma_2012@hotmail.com>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/
#include <stdint.h>



extern void i387_to_double (char *from, char *to);
extern void double_to_i387 (char *from, char *to);

struct reg_pack
{
	// The ordering is very important, don't change
	// The first field is the last to be pushed and first to be poped
	
	enum reg_name
	{
		reg_edi, reg_esi, reg_ebp, reg_esp, reg_ebx, reg_edx, reg_ecx, reg_eax 
	};
	
	enum ef_flag
	{
		carry_flag = 0, parity_flag = 2, adjust_flag = 4, zero_flag = 6, sign_flag = 7,
		direction_flag = 10, overflow_flag = 11
	};
	
	// FSAVE / FRSTOR
	#pragma pack(push, 1)
	struct
	{
		uint32_t			cwd;	/* FPU Control Word		*/
		uint32_t			swd;	/* FPU Status Word		*/
		uint32_t			twd;	/* FPU Tag Word			*/
		uint32_t			fip;	/* FPU IP Offset		*/
		uint32_t			fcs;	/* FPU IP Selector		*/
		uint32_t			foo;	/* FPU Operand Pointer Offset	*/
		uint32_t			fos;	/* FPU Operand Pointer Selector	*/
	
		/* 8*10 bytes for each FP-reg = 80 bytes:			*/
		struct
		{
			uint32_t sigl; // low
			uint32_t sigh; // high
			int16_t exp;
			
			/*
			void Set(double v)
			{
				double_to_i387((char *)&v, (char *)this);
			}
			
			double Get()
			{
				double v;
				i387_to_double((char *)this, (char *)&v);
				return v;
			}
			*/
			
		}st[8];
	}fpu;
	#pragma pack(pop)
	
	
	// PUSHAD/POPAD -- must be the lastest fields (because of esp)
	union
	{
		uint32_t arr[8];
		struct { uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; };
	}cpu;
	
	// PUSHFD / POPFD
	uint32_t ef;

	
	template<uint32_t bit>   // bit starts from 0, use ef_flag enum
	bool flag()
	{
		return (this->ef & (1 << bit)) != 0;
	}
	
	bool jnb()
	{
		return flag<carry_flag>() == false;
	}
	
	void PutJump(int address)
	{
		*(uintptr_t*)cpu.esp = address;
	}
};

template<class W>   // where W is of type wrapper
inline void __declspec(naked) make_reg_pack_and_call()
{
    _asm
    {
		// Construct the reg_pack structure on the stack
		pushfd              // Pushes EFLAGS to reg_pack
		pushad              // Pushes general purposes registers to reg_pack
		
		add dword ptr[esp+12], 8     // Add 4 to reg_pack::esp 'cuz of our return pointer, let it be as before this func is called
		
		sub	esp,108
		fsave dword ptr[esp]
		
		
		// Call wrapper sending reg_pack as parameter
		push esp
		call W::call
		add esp, 4
		
		// Destructs the reg_pack from the stack
		
		frstor dword ptr[esp]
		add	esp,108

		sub dword ptr[esp+12], 8   // Fix reg_pack::esp before popping it (doesn't make a difference though) (+4 because eflags)
		
		popad
		popfd               // Warning: Do not use any instruction that changes EFLAGS after this (-> sub affects EF!! <-)
		
		// Back to normal flow
		ret
    }
}

template<typename T>
struct wrapper
{
    static void call(reg_pack* regs)
    {
		T fun; fun(*regs);
    }
};

template <typename T> void * func2ptr(T o)
{
	auto member = o;
	void*& ptr = (void*&)member;
	return ptr;
}

template<class FuncT>
void *GetInlineHookPtr()
{
	typedef wrapper<FuncT> functor;
	if(false) functor::call(NULL);   // To instantiate the template, if not done _asm will fail
	
	return func2ptr(make_reg_pack_and_call<functor>);
}

/*
template<class FuncT>
void MakeInline(int address)
{
	typedef wrapper<FuncT> functor;
	if(false) functor::call(NULL);   // To instantiate the template, if not done _asm will fail
	CPatch::RedirectCall(address, make_reg_pack_and_call<functor>);
}
*/