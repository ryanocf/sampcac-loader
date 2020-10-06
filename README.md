<div align="center">
    <p style="font-size: 32px"><b>sampcac-loader</b></p>
    <img src="https://img.shields.io/badge/License-MIT-important?style=flat-square" />
    <img src="https://img.shields.io/badge/%E2%80%8E-C++-00599C?style=flat-square&logoWidth=20&logo=image/svg+xml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+QysrIGljb248L3RpdGxlPjxwYXRoIGZpbGw9IndoaXRlIiBkPSJNMjIuMzkzIDZjLS4xNjctLjI5LS4zOTgtLjU0My0uNjUyLS42OUwxMi45MjUuMjJjLS41MDgtLjI5My0xLjMzOS0uMjkzLTEuODQ3IDBMMi4yNiA1LjMxYy0uNTA4LjI5My0uOTIzIDEuMDEzLS45MjMgMS42djEwLjE4YzAgLjI5NC4xMDQuNjIuMjcxLjkxLjE2Ny4yOS4zOTguNTQzLjY1Mi42ODlsOC44MTYgNS4wOTFjLjUwOC4yOTMgMS4zMzkuMjkzIDEuODQ3IDBsOC44MTYtNS4wOTFjLjI1NC0uMTQ2LjQ4NS0uMzk5LjY1Mi0uNjg5cy4yNzEtLjYxNi4yNzEtLjkxVjYuOTFjLjAwMi0uMjk0LS4xMDItLjYyLS4yNjktLjkxek0xMiAxOS4xMDljLTMuOTIgMC03LjEwOS0zLjE4OS03LjEwOS03LjEwOVM4LjA4IDQuODkxIDEyIDQuODkxYTcuMTMzIDcuMTMzIDAgMCAxIDYuMTU2IDMuNTUybC0zLjA3NiAxLjc4MUEzLjU2NyAzLjU2NyAwIDAgMCAxMiA4LjQ0NWMtMS45NiAwLTMuNTU0IDEuNTk1LTMuNTU0IDMuNTU1UzEwLjA0IDE1LjU1NSAxMiAxNS41NTVhMy41NyAzLjU3IDAgMCAwIDMuMDgtMS43NzhsMy4wNzcgMS43OEE3LjEzNSA3LjEzNSAwIDAgMSAxMiAxOS4xMDl6bTcuMTA5LTYuNzE0aC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc5di0uNzloLjc5di0uNzloLjc5di43OWguNzl2Ljc5em0yLjk2MiAwaC0uNzl2Ljc5aC0uNzl2LS43OWgtLjc4OXYtLjc5aC43ODl2LS43OWguNzl2Ljc5aC43OXYuNzl6Ii8+PC9zdmc+" />
    <img src="https://img.shields.io/badge/%E2%80%8E-Autohotkey-7ac673?style=flat-square&logoWidth=20&logo=image/png;base64,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" />
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

https://github.com/DarthTon/Blackbone
