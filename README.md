# <div align="center">sampcac-loader</div>

<div align="center">
    <img src="https://img.shields.io/badge/License-MIT-important?style=flat-square" />
    <img src="https://img.shields.io/badge/%E2%80%8E-C++-00599C?style=flat-square&logoWidth=20&logo=image/svg+xml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+QysrIGljb248L3RpdGxlPjxwYXRoIGZpbGw9IndoaXRlIiBkPSJNMjIuMzkzIDZjLS4xNjctLjI5LS4zOTgtLjU0My0uNjUyLS42OUwxMi45MjUuMjJjLS41MDgtLjI5My0xLjMzOS0uMjkzLTEuODQ3IDBMMi4yNiA1LjMxYy0uNTA4LjI5My0uOTIzIDEuMDEzLS45MjMgMS42djEwLjE4YzAgLjI5NC4xMDQuNjIuMjcxLjkxLjE2Ny4yOS4zOTguNTQzLjY1Mi42ODlsOC44MTYgNS4wOTFjLjUwOC4yOTMgMS4zMzkuMjkzIDEuODQ3IDBsOC44MTYtNS4wOTFjLjI1NC0uMTQ2LjQ4NS0uMzk5LjY1Mi0uNjg5cy4yNzEtLjYxNi4yNzEtLjkxVjYuOTFjLjAwMi0uMjk0LS4xMDItLjYyLS4yNjktLjkxek0xMiAxOS4xMDljLTMuOTIgMC03LjEwOS0zLjE4OS03LjEwOS03LjEwOVM4LjA4IDQuODkxIDEyIDQuODkxYTcuMTMzIDcuMTMzIDAgMCAxIDYuMTU2IDMuNTUybC0zLjA3NiAxLjc4MUEzLjU2NyAzLjU2NyAwIDAgMCAxMiA4LjQ0NWMtMS45NiAwLTMuNTU0IDEuNTk1LTMuNTU0IDMuNTU1UzEwLjA0IDE1LjU1NSAxMiAxNS41NTVhMy41NyAzLjU3IDAgMCAwIDMuMDgtMS43NzhsMy4wNzcgMS43OEE3LjEzNSA3LjEzNSAwIDAgMSAxMiAxOS4xMDl6bTcuMTA5LTYuNzE0aC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc5di0uNzloLjc5di0uNzloLjc5di43OWguNzl2Ljc5em0yLjk2MiAwaC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc4OXYtLjc5aC43ODl2LS43OWguNzl2Ljc5aC43OXYuNzl6Ii8+PC9zdmc+" />
    <img src="https://i.imgur.com/uGOBMAO.png" />
    <br/><br/>
    Bypassing SAMPCAC's protection of the samp.dll module in a very hacky and basic way.<br/>
    This project is meant for people who want to use the <a href="https://github.com/SAMP-UDF/SAMP-UDF-for-AutoHotKey">SAMP-UDF</a> in their Autohotkey application.
</div>

___

## Usage

First you need to copy the following code in your Autohotkey application **BEFORE** you include the SAMP-UDF.<br/>
:exclamation: **The <kbd>**sampcac-loader.exe**</kbd> and <kbd>**sampcac-loader.dll**</kbd> have to be in a folder called <kbd>**dll**</kbd>**<br/>
:exclamation: **If you want to use another path or other file name then you have to modify and build the sampcac-loader yourself.**

```ahk
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
```
___
If you have your own SAMP-UDF or something similiar then you have to modify it in order to get this bypass to work.<br/>
Replace the following functions in your SAMP-UDF or copy and paste the additional code.<br/>
:exclamation: **Skip this step if you use the SAMP-UDF from the example**

```ahk
refreshGTA() {
    newPID := getPID(gta_title) ; <--- modified
    if (!newPID) {
        if (hGTA) {
            virtualFreeEx(hGTA, pMemory, 0, 0x8000)
            closeProcess(hGTA)
            hGTA := 0x0
        }
        dwGTAPID := 0
        hGTA := 0x0
        dwSAMP := 0x0
        pMemory := 0x0
        return false
    }
    
    if (!hGTA || (dwGTAPID != newPID)) {
        hGTA := openProcess(newPID)
        if (ErrorLevel) {
            dwGTAPID := 0
            hGTA := 0x0
            dwSAMP := 0x0
            pMemory := 0x0
            return false
        }
        dwGTAPID := newPID
        dwSAMP := 0x0
        pMemory := 0x0
        return true
    }
    return true
}
```

```ahk
refreshSAMP() {
    if (dwSAMP)
        return true
    
    ;applying bypass
    dwSAMP := sampcac_mode ? "0x" + sampdll_base_address : getModuleBaseAddress("samp.dll", hGTA)

    if (!dwSAMP)
        return false

    versionByte := readMem(hGTA, dwSAMP + 0x1036, 1, "UChar")
    sampVersion := versionByte == 0xD8 ? 1 : (versionByte == 0xA8 ? 2 : (versionByte == 0x78 ? 3 : 0))
    if (!sampVersion)
    	return false

    return true
}
```

___

If you have applied everything correctly then you should be able to use everything that is provided in the SAMP-UDF.

Any questions or problems?<br/>
Feel free to open an [issue](https://github.com/ryanocf/sampcac-loader/issues/new).

## Credits

https://github.com/DarthTon/Blackbone<br/>
https://github.com/boostorg/algorithm
