# PowerShell script to remove images and reformat HTML

# Read the original HTML file
$inputFile = "i:\NWPOS\SR600Mini\MFSDKAPIDiscription.html"
$outputFile = "i:\NWPOS\SR600Mini\MFSDKAPIDiscription_clean.html"

Write-Host "Reading HTML file..."
$content = Get-Content $inputFile -Raw

Write-Host "Original file size: $($content.Length) characters"

# Remove all image-related content
Write-Host "Removing images..."

# Remove img tags and their containing spans
$content = $content -replace '<span[^>]*?overflow:[^>]*?><img[^>]*?></span>', ''

# Remove standalone img tags
$content = $content -replace '<img[^>]*?>', ''

# Remove empty spans that might be left over
$content = $content -replace '<span[^>]*?>\s*</span>', ''

# Add proper line breaks for better formatting
Write-Host "Formatting HTML..."

# Add line breaks after major HTML elements
$content = $content -replace '></head>', ">`n</head>"
$content = $content -replace '><body', ">`n<body"
$content = $content -replace '</body>', "`n</body>"
$content = $content -replace '</html>', "`n</html>"
$content = $content -replace '><title', ">`n<title"
$content = $content -replace '</title>', "</title>`n"
$content = $content -replace '><style', ">`n<style"
$content = $content -replace '</style>', "</style>`n"
$content = $content -replace '><p', ">`n<p"
$content = $content -replace '</p>', "</p>`n"
$content = $content -replace '><div', ">`n<div"
$content = $content -replace '</div>', "</div>`n"
$content = $content -replace '><h([1-6])', ">`n<h`$1"
$content = $content -replace '</h([1-6])>', "</h`$1>`n"
$content = $content -replace '><table', ">`n<table"
$content = $content -replace '</table>', "</table>`n"
$content = $content -replace '><tr', ">`n  <tr"
$content = $content -replace '</tr>', "</tr>`n"
$content = $content -replace '><td', ">`n    <td"
$content = $content -replace '</td>', "</td>`n"
$content = $content -replace '><ol', ">`n<ol"
$content = $content -replace '</ol>', "</ol>`n"
$content = $content -replace '><ul', ">`n<ul"
$content = $content -replace '</ul>', "</ul>`n"
$content = $content -replace '><li', ">`n  <li"
$content = $content -replace '</li>', "</li>`n"

# Clean up multiple consecutive line breaks
$content = $content -replace "`n`n+", "`n`n"

Write-Host "Cleaned file size: $($content.Length) characters"

# Write the cleaned content to a new file
Write-Host "Writing cleaned HTML file..."
$content | Out-File -FilePath $outputFile -Encoding UTF8

Write-Host "Cleanup complete! Cleaned file saved as: $outputFile"
Write-Host "Images removed and HTML formatted for better readability."
