#pragma once 

#define APOSENDIANLITTLE

//
// engine macros
//
#define APOSDEBUGTRAP() __builtin_trap()
// APOSCHECK asserts in debug builds, but does not evaluate or execute in release
#ifdef APOSBUILDDEBUG
#define APOSCHECK(x)                                                            \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			APOSDEBUGBREAK();                                                   \
		}                                                                      \
	} while (0)
#else
#define APOSCHECK(x)                                                            \
	do                                                                         \
	{                                                                          \
	} while (0)
#endif
// APOSVERIFY
// APOSVERIFY asserts only in debug builds, but still evaluates and executes in
// release
#ifdef APOSBUILDDEBUG
#define APOSVERIFY(x)                                                           \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			APOSDEBUGBREAK();                                                   \
		}                                                                      \
	} while (0)
#else
#define APOSVERIFY(x)                                                           \
	do                                                                         \
	{                                                                          \
		x;                                                                     \
	} while (0)
#endif