@echo off
    for /f "delims=" %%a in (D:\Git\2.txt) do (
    cd ..
    git commit -m %%a
    ) 
    pause