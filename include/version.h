/*
* Super Entity Game Server
* http://segs.sf.net/
* Copyright (c) 2006 Super Entity Game Server Team (see AUTHORS.md)
* This software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.
*
*/

#define VersionString "segs v0.5.0 (The Unsilencer)";
#define CopyrightString "Super Entity Game Server\nhttp://github.com/Segs/\nCopyright (c) 2006-2018 Super Entity Game Server Team (see AUTHORS.md)\nThis software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.\n";
//const char *AdminVersionString="Undefined";
//const char *AuthVersionString="Undefined";
//const char *GameVersionString="Undefined";
//const char *MapVersionString="Undefined";

// Contains version information for the various server modules
class VersionInfo
{
public:
    static const char *getAdminVersion(void);
    static const char *getAuthVersion(void)
{
        return VersionString;
}

    static const char *getGameVersion(void);
    static const char *getMapVersion(void);
    static const char *getCopyright(void)
{
        return CopyrightString;
}
};

#undef VersionString
#undef CopyrightString

