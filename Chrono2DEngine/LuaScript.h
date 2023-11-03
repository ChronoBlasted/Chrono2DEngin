#pragma once
#include <lua.hpp>
#include <string>

namespace CH {
	class LuaScript {
	public:
		void SetScript(std::string assetID);
	protected:
	private:
		lua_State* _luaState;

		void ReportErrors(lua_State* luaState, int status);
	};
}


