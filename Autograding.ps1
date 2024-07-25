$parcialName = "template"
$ValidOutputName = "ValidOutput_"
$TestOutputName = "TestOutput_"
$resourcesPath = ".\resources"


# Compiling the C file
gcc -o "$parcialName.exe" "$parcialName.c"

# Running the compiled file with different inputs and storing the outputs
@(500, 10), @(900, 100), @(50, 2)| ForEach-Object -Begin { $i = 1 } -Process {
    $output = echo $_[0], $_[1] | & ".\$parcialName.exe"
    $output | Out-File -FilePath "$resourcesPath\$TestOutputName$i.txt"
    $i++
}

# Comparing the output files with the valid output files
1..3 | ForEach-Object {
    
    $filetext1=[System.IO.File]::ReadAllText("$resourcesPath\$ValidOutputName$_.txt")
    $filetext2=[System.IO.File]::ReadAllText("$resourcesPath\$TestOutputName$_.txt")
    $equal = $filetext1 -ceq $filetext2
    if ($equal -eq $true) 
    {        
        Write-Output "Los archivos $ValidOutputName y $TestOutputName son identicos."
    } else {
        Write-Output "Los archivos $ValidOutputName y $TestOutputName son diferentes."
    }
}


