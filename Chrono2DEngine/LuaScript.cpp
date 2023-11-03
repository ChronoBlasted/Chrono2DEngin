#include "LuaScript.h"
#include <iostream>
#include "Application.h"
#include "RessourceManager.h"

void CH::LuaScript::SetScript(std::string assetID)
{
	std::string path = CH::RessourceManager::GetInstance()->GetPathById(assetID);

	int scriptLoadStatus = luaL_dofile(_luaState, path.c_str());

	ReportErrors(_luaState, scriptLoadStatus);
}


void CH::LuaScript::ReportErrors(lua_State* luaState, int status)
{
	if (status == 0) {
		return;
	}

	std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;

	lua_pop(luaState, 1);
}
