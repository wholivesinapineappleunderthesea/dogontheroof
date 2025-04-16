#pragma once

#include <cstdint>

using aposU8 = std::uint8_t;
using aposU16 = std::uint16_t;
using aposU32 = std::uint32_t;
using aposU64 = std::uint64_t;
using aposS8 = std::int8_t;
using aposS16 = std::int16_t;
using aposS32 = std::int32_t;
using aposS64 = std::int64_t;
using aposF32 = float;
using aposF64 = double;

using aposBool = bool;

using aposChar = char;
using aposWChar = wchar_t;

using aposSize = size_t;
using aposSSize = ptrdiff_t;

using aposObjectID = aposU64;

#include "Math/Defs.h"
#include "Math/Hash.h"
#include "Math/Random.h"

#include "Containers/SPSCQueue.h"

namespace apostate
{
	/**
	 * @brief A non-copyable type to be inherited from. Expresses clearly that a
	 * type cannot be copied.
	 *
	 */
	struct NonCopyable
	{
		NonCopyable() = default;
		NonCopyable(const NonCopyable &) = delete;
		NonCopyable &operator=(const NonCopyable &) = delete;
	};

	enum ControllerButton : aposU8
	{
		ControllerButton_LeftThumb,
		ControllerButton_RightThumb,
		ControllerButton_LeftShoulder,
		ControllerButton_RightShoulder,
		ControllerButton_South,
		ControllerButton_East,
		ControllerButton_West,
		ControllerButton_North,
		ControllerButton_StartSelect,
		ControllerButton_BackShare,
		ControllerButton_DPadUp,
		ControllerButton_DPadDown,
		ControllerButton_DPadLeft,
		ControllerButton_DPadRight,
		ControllerButton_Count
	};

	enum ControllerAxis : aposU8
	{
		ControllerAxis_LeftThumbX,
		ControllerAxis_LeftThumbY,
		ControllerAxis_RightThumbX,
		ControllerAxis_RightThumbY,
		ControllerAxis_LeftTrigger,
		ControllerAxis_RightTrigger,
		ControllerAxis_Count
	};

	enum MouseButton : aposU8
	{
		MouseButton_Left,
		MouseButton_Right,
		MouseButton_Middle,
		MouseButton_X1,
		MouseButton_X2,
		MouseButton_Count
	};

	enum KeyboardButton : aposU8
	{
		// A-Z
		KeyboardButton_A,
		KeyboardButton_B,
		KeyboardButton_C,
		KeyboardButton_D,
		KeyboardButton_E,
		KeyboardButton_F,
		KeyboardButton_G,
		KeyboardButton_H,
		KeyboardButton_I,
		KeyboardButton_J,
		KeyboardButton_K,
		KeyboardButton_L,
		KeyboardButton_M,
		KeyboardButton_N,
		KeyboardButton_O,
		KeyboardButton_P,
		KeyboardButton_Q,
		KeyboardButton_R,
		KeyboardButton_S,
		KeyboardButton_T,
		KeyboardButton_U,
		KeyboardButton_V,
		KeyboardButton_W,
		KeyboardButton_X,
		KeyboardButton_Y,
		KeyboardButton_Z,

		// 0-9
		KeyboardButton_0,
		KeyboardButton_1,
		KeyboardButton_2,
		KeyboardButton_3,
		KeyboardButton_4,
		KeyboardButton_5,
		KeyboardButton_6,
		KeyboardButton_7,
		KeyboardButton_8,
		KeyboardButton_9,

		// F1-F24
		KeyboardButton_F1,
		KeyboardButton_F2,
		KeyboardButton_F3,
		KeyboardButton_F4,
		KeyboardButton_F5,
		KeyboardButton_F6,
		KeyboardButton_F7,
		KeyboardButton_F8,
		KeyboardButton_F9,
		KeyboardButton_F10,
		KeyboardButton_F11,
		KeyboardButton_F12,
		KeyboardButton_F13,
		KeyboardButton_F14,
		KeyboardButton_F15,
		KeyboardButton_F16,
		KeyboardButton_F17,
		KeyboardButton_F18,
		KeyboardButton_F19,
		KeyboardButton_F20,
		KeyboardButton_F21,
		KeyboardButton_F22,
		KeyboardButton_F23,
		KeyboardButton_F24,

		// Numpad 0-9
		KeyboardButton_NumPad0,
		KeyboardButton_NumPad1,
		KeyboardButton_NumPad2,
		KeyboardButton_NumPad3,
		KeyboardButton_NumPad4,
		KeyboardButton_NumPad5,
		KeyboardButton_NumPad6,
		KeyboardButton_NumPad7,
		KeyboardButton_NumPad8,
		KeyboardButton_NumPad9,

		// Numpad etc
		KeyboardButton_NumPadDecimal,
		KeyboardButton_NumPadEnter,
		KeyboardButton_NumPadAdd,
		KeyboardButton_NumPadSubtract,
		KeyboardButton_NumPadMultiply,
		KeyboardButton_NumPadDivide,
		KeyboardButton_NumPadLock,

		// Arrow keys
		KeyboardButton_Left,
		KeyboardButton_Right,
		KeyboardButton_Up,
		KeyboardButton_Down,

		// Home/End, Page Up/Down, Insert/Delete
		KeyboardButton_Home,
		KeyboardButton_End,
		KeyboardButton_PageUp,
		KeyboardButton_PageDown,
		KeyboardButton_Insert,
		KeyboardButton_Delete,

		// Pause/Break, Print Screen, Scroll Lock
		KeyboardButton_Pause,
		KeyboardButton_PrintScreen,
		KeyboardButton_ScrollLock,

		// Escape, Backtick, Tab, Caps Lock, Left Shift, Left Control, Left
		// Windows, Left Alt
		KeyboardButton_Escape,
		KeyboardButton_Backtick,
		KeyboardButton_Tab,
		KeyboardButton_CapsLock,
		KeyboardButton_LeftShift,
		KeyboardButton_LeftControl,
		KeyboardButton_LeftWindows,
		KeyboardButton_LeftAlt,

		// Space
		KeyboardButton_Space,

		// Right Alt, Right Function, Right Menu, Right Control, Right Shift,
		// Enter, Backspace
		KeyboardButton_RightAlt,
		KeyboardButton_RightFunction,
		KeyboardButton_RightMenu,
		KeyboardButton_RightControl,
		KeyboardButton_RightShift,
		KeyboardButton_Enter,
		KeyboardButton_Backspace,

		// Comma, Period, Slash, Semicolon, Apostrophe, Left Bracket, Right
		// Bracket, Backslash, Hyphen, Equals
		KeyboardButton_Comma,
		KeyboardButton_Period,
		KeyboardButton_Slash,
		KeyboardButton_Semicolon,
		KeyboardButton_Apostrophe,
		KeyboardButton_LeftBracket,
		KeyboardButton_RightBracket,
		KeyboardButton_Backslash,
		KeyboardButton_Hyphen,
		KeyboardButton_Equals,

		KeyboardButton_Count
	};

	template <typename TRet, typename... TArgs>
	struct CallbackList
	{
		using fnptr_type = TRet (*)(void *, TArgs...);

		auto AddCallback(std::weak_ptr<void> obj, fnptr_type fn) -> void
		{
			m_callbacks.emplace_back(std::move(obj), fn);
		}

		template <typename TFun>
		auto IterateCallbacks(TFun &&fun, TArgs... args)

			-> void
			requires(not std::same_as<void, TRet>)
		{
			for (auto it = m_callbacks.begin(); it != m_callbacks.end();)
			{
				auto &[obj, fn] = *it;
				if (auto sp = obj.lock())
				{
					fun(fn(sp, std::forward<TArgs>(args)...));
					++it;
				}
				else
				{
					it = m_callbacks.erase(it);
				}
			}
		}

		template <typename TFun>
		auto IterateCallbacks(TFun &&fun, TArgs... args)

			-> void
		{
			for (auto it = m_callbacks.begin(); it != m_callbacks.end();)
			{
				auto &[obj, fn] = *it;
				if (auto sp = obj.lock())
				{
					fn(sp.get(), std::forward<TArgs>(args)...);
					fun();
					++it;
				}
				else
				{
					it = m_callbacks.erase(it);
				}
			}
		}

	private:
		std::vector<std::pair<std::weak_ptr<void>, fnptr_type>> m_callbacks;
	};

}; // namespace aposgen