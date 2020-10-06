#SingleInstance, Force
#Persistent
#NoEnv
SetBatchLines -1
SetKeyDelay -1

global sampcac_mode := false
global sampdll_base_address := 0

WinGetTitle, gta_title, ahk_exe gta_sa.exe
global gta_title

WinGet, gta_process, ProcessName, %gta_title%
WinGet, gta_path, ProcessPath, %gta_title%
WinGet, gta_pid, PID, %gta_title%
gta_folder := StrReplace(gta_path, gta_process, "", "Off")
Loop, Files, %gta_folder%*, F
{
    if (RegExMatch(A_LoopFileName, "sampcac") && A_LoopFileExt == "asi") {
        msgbox, 0x40044, Loader, sampcac found!`nDo you want to start with sampcac mode?
        IfMsgBox Yes
            init_sampcac()
    }
}

init_sampcac() {
    global
    sampcac_mode := true
    Run *RunAs %A_ScriptDir%\dll\sampcac-loader.exe
    sleep 5000

    FileReadLine, sampdll_base_address, %gta_folder%\samp.dat, 1
}

#include SAMP.ahk

_name := GetPlayerName()
_id := GetPlayerId()
_hp := GetPlayerHealth()
_armor := GetPlayerArmor()
_skin := GetPlayerSkinId()

if (_id == -1) {
    msgbox, 0x40010, Fuck, Something went wrong :(, 5
    ExitApp
    return
}

AddChatMessage("{e84621}[ryano.cf]{FFFFFF} " _name " (ID: " _id ") - HP: " _hp " - Armor: " _armor " - Skin: " _skin)
msgbox, 0x40040, Loader, Success`nYou can now open GTA and look for yourself :)`n`nClosing in 5s..., 5

ExitApp

return