# Define variables
$CLEANUP = $false

# Parse command-line arguments
$opts = Getopt::Std.Getopts("c")

foreach ($opt in $opts.Keys) {
  switch ($opt) {
    "c" { $CLEANUP = $true }
    default { Write-Host "Invalid option: -$opt" -ForegroundColor Red; exit 1 }
  }
}

if ($CLEANUP) {
  # Cleanup
  Remove-Item -Path _* -Recurse -Force
}

# Create a build directory and navigate into it
if (-not (Test-Path "_build")) {
  New-Item -ItemType Directory -Name "_build" | Out-Null
}
Set-Location "_build"

# Run CMake to generate the build files
cmake -DCODE_COVERAGE=ON -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..

# Build the project using make
cmake --build . --target all test

# Generate the coverage report using lcov
make coverage

Set-Location ..
