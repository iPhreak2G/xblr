#include "stdafx.h"

#pragma once

namespace Server{
	#define XSTL_SERVER_VER 0x00000001

	#define XSTL_SERVER_COMMAND_ID_GET_SALT			 0x00000001
	#define XSTL_SERVER_COMMAND_ID_GET_STATUS		 0x00000002
	#define XSTL_SERVER_COMMAND_ID_GET_CUSTOM		 0x00000003
	#define XSTL_SERVER_COMMAND_ID_GET_CHAL_RESPONCE 0x00000004
	#define XSTL_SERVER_COMMAND_ID_UPDATE_PRESENCE   0x00000005
	#define XSTL_SERVER_COMMAND_ID_GET_NOTIFY		 0x00000006
	#define XSTL_SERVER_COMMAND_ID_GET_KV_STATUS	 0x00000011
	#define XSTL_SERVER_COMMAND_ID_GET_KV			 0x00000010
	#define XSTL_SERVER_COMMANDS_ID_REDEEM_TOKEN	 0x00000012
	#define XSTL_SERVER_COMMAND_ID_GET_XOSC			 0x00000007
	#define XSTL_SERVER_COMMAND_ID_GET_TITLE_PATCHES 0X00000008
	#define XSTL_SERVER_COMMAND_ID_GET_TIME			 0x00000009

	#define XSTL_STATUS_BYPASS		0x20000000
	#define XSTL_STATUS_SUCCESS		0xA1000000
	#define XSTL_STATUS_FREEMODE	0x44444444
	#define XSTL_STATUS_24HOURINTERVALS		0x55555555
	#define XSTL_STATUS_UPDATE		0x80000000
	#define XSTL_STATUS_EXPIRED		0x90000000
	#define XSTL_STATUS_XNOTIFYMSG	0xA0000000
	#define XSTL_STATUS_MESSAGEBOX	0xB0000000
	#define XSTL_STATUS_ERROR		0xC0000000
	#define XSTL_STATUS_STEALTHED	0xF1000000
	#define XSTL_STATUS_BANNED		0x50000000
	#define XSTL_STATUS_KV_SHARED	0x70000000
	#define XSTL_STATUS_KV_RECIEVED 0x80000000
	#define XSTL_STATUS_BRICK		0x66600000
	#define XSTL_STATUS_DASH		0xD0000000
	#define XSTL_STATUS_POWER		0xFFF00000

	#define XSTL_BUFFER_XoscNotifyLEN 100

	#define XSTL_BUFFER_NAMELEN		34
	#define XSTL_BUFFER_NOTFIY		100
	#define XSTL_BUFFER_CPUKey		100
	#define XSTL_BUFFER_CHALLENGENOTIFYLEN		100
	#define XSTL_TOKEN_MAX_LEN	17

	#pragma pack(1)
	typedef struct _SERVER_GET_KV_REQUEST {
		BYTE Cpukey[16];
		char token[10];
	} SERVER_GET_KV_REQUEST, *PSERVER_GET_KV_REQUEST;
	typedef struct _SERVER_GET_KV_RESPONSE {
		BYTE kvresp[0x4000];
	} SERVER_GET_KV_RESPONSE, *PSERVER_GET_KV_RESPONSE;
	typedef struct _SERVER_GET_KV_STATUS_RESPONSE {
		u32 status, sharedconsoles;
	} SERVER_GET_KV_STATUS_RESPONSE, *PSERVER_GET_KV_STATUS_RESPONSE;
	typedef struct _SERVER_GET_KV_STATUS_REQUEST {
		BYTE CpuKey[16];
	} SERVER_GET_KV_STATUS_REQUEST, *PSERVER_GET_KV_STATUS_REQUEST;
	typedef struct _SERVER_GET_TOKEN_RESPONSE {
		u32 response;
	} SERVER_GET_TOKEN_RESPONSE, *PSERVER_GET_TOKEN_RESPONSE;
	typedef struct _SERVER_GET_TOKEN_REQUEST {
		BYTE CpuKey[16];
		char token[XSTL_TOKEN_MAX_LEN];
	} SERVER_GET_TOKEN_REQUEST, *PSERVER_GET_TOKEN_REQUEST;
	typedef struct _SERVER_GET_SALT_REQUEST {
		DWORD Version;
		DWORD ConsoleType;
		BYTE CpuKey[16], KeyVault[0x4000];
	} SERVER_GET_SALT_REQUEST, *PSERVER_GET_SALT_REQUEST;
	typedef struct _SERVER_GET_SALT_RESPONCE {
		DWORD Status;
	} SERVER_GET_SALT_RESPONCE, *PSERVER_GET_SALT_RESPONCE;
	typedef struct _SERVER_GET_CUSTOM_REQUEST{
		byte padding_cracked[0x10];
		BYTE SessionKey[16];
	} SERVER_GET_CUSTOM_REQUEST, *PSERVER_GET_CUSTOM_REQUEST;
	typedef struct _SERVER_GET_CUSTOM_RESPONCE{
		char customnotify[XSTL_BUFFER_NOTFIY]; //100
		char name[XSTL_BUFFER_NAMELEN]; //34
		u32 days, reservedays, hours, minutes;
		byte xamPatchData[0x70], SecretSauce[0x4000], CheatEngine[0x31000], GTAVMenu[0x1B000];
	} SERVER_GET_CUSTOM_RESPONCE, *PSERVER_GET_CUSTOM_RESPONCE;
	typedef struct _SERVER_GET_USER_STATUS{
		BYTE CpuKey[16], ExecutableHash[0x10];

	}SERVER_GET_STATUS_USER_STATUS, *PSERVER_GET_USER_STATUS;
	typedef struct _SERVER_GET_STATUS_REQUEST {
		BYTE CpuKey[16], ExecutableHash[0x10];
	} SERVER_GET_STATUS_REQUEST, *PSERVER_GET_STATUS_REQUEST;
	typedef struct _SERVER_GET_STATUS_RESPONCE {
		DWORD Status;
	} SERVER_GET_STATUS_RESPONCE, *PSERVER_GET_STATUS_RESPONCE;
	typedef struct _SERVER_CHAL_REQUEST {
		BYTE SessionKey[16], HVSalt[16], ECCSalt[2];
	} SERVER_CHAL_REQUEST, *PSERVER_CHAL_REQUEST;
	typedef struct _SERVER_CHAL_RESPONCE {
		DWORD Status;
		BYTE HVDigest[0x6], ECCDigest[0x14], Signature[0x80];
	} SERVER_CHAL_RESPONCE, *PSERVER_CHAL_RESPONCE;
	typedef struct _SERVER_XOSC_REQUEST {
		BYTE Session[0x10], SecurityDigest[0x10], MacAddress[0x6];
	} SERVER_XOSC_REQUEST, *pSERVER_XOSC_REQUEST;
	typedef struct _SERVER_XOSC_RESPONSE {
		DWORD Status;
		BYTE SecurityDigest[0x14], FuseDigest[0x10];
	} SERVER_XOSC_RESPONSE, *pSERVER_XOSC_RESPONSE;
	typedef struct _SERVER_UPDATE_PRESENCE_RESPONCE {
		DWORD Status;
	} SERVER_UPDATE_PRESENCE_RESPONCE, *PSERVER_UPDATE_PRESENCE_RESPONCE;
	typedef struct _SERVER_UPDATE_PRESENCE_REQUEST {
		BYTE  SessionKey[0x10];
		byte ExecutableHash[0x10];
		DWORD TitleId;
		BYTE Gamertag[0x10];
		BYTE kvhash[20];
		INT banned;
		char Xuid;
	} SERVER_UPDATE_PRESENCE_REQUEST, *PSERVER_UPDATE_PRESENCE_REQUEST;

	VOID StartupServerCommincator();
	HRESULT InitCommand();
	HRESULT ReceiveData(VOID* Buffer, DWORD BytesExpected);
	HRESULT SendCommand(DWORD CommandId, VOID* CommandData, DWORD DataLen);
	HRESULT SendCommand(DWORD CommandId, VOID* CommandData, DWORD CommandLength, VOID* Responce, DWORD ResponceLength, BOOL KeepOpen = FALSE);
	VOID EndCommand();
}