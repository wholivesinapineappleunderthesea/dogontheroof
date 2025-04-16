#pragma once

namespace apostate
{
	inline std::random_device g_randomDevice;
	inline std::mt19937_64 g_randomEngine{g_randomDevice()};
	inline auto RandomS32(aposS32 minInclusive, aposS32 maxInclusive) -> aposS32
	{
		std::uniform_int_distribution<aposS32> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomU32(aposU32 minInclusive, aposU32 maxInclusive) -> aposU32
	{
		std::uniform_int_distribution<aposU32> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomS64(aposS64 minInclusive, aposS64 maxInclusive) -> aposS64
	{
		std::uniform_int_distribution<aposS64> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomU64(aposU64 minInclusive, aposU64 maxInclusive) -> aposU64
	{
		std::uniform_int_distribution<aposU64> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomF32(aposF32 minInclusive, aposF32 maxInclusive) -> aposF32
	{
		std::uniform_real_distribution<aposF32> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomF64(aposF64 minInclusive, aposF64 maxInclusive) -> aposF64
	{
		std::uniform_real_distribution<aposF64> dist{minInclusive, maxInclusive};
		return dist(g_randomEngine);
	}
	inline auto RandomBool() -> aposBool
	{
		std::bernoulli_distribution dist;
		return dist(g_randomEngine);
	}

}; // namespace aposgen