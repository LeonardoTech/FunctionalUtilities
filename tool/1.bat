@echo off
    for /f "delims=" %%a in (C:\WorkSpace\FunctionalUtilities\2.txt) do (
    git commit -m %%a
    ) 
    pause