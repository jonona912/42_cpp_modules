#!/bin/bash
# when # is immediately followed by ! as the first two characters of the file, it’s treated 
# as a shebang, not a comment.
# The #! at the beginning of a file is a special sequence called a shebang (or hashbang). 
# It’s a magic number recognized by the operating system (Unix-like systems like Linux or 
# macOS) to indicate that the file is a script and specify which interpreter should run it.
# In #!/bin/bash, the #! tells the system to use the program at /bin/bash (the Bash shell) 
# to execute the script. The rest of the line (e.g., /bin/bash) is the path to the interpreter.

output=$(./megaphone "shhhhh... I think the students are asleep...")
if [ "$output" = "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." ]; then
	echo -e "\e[32mFirst test passed\e[0m"
	echo -e "\e[32mExpected: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\e[0m"
	echo -e "\e[32mGot:      $output\e[0m"
else
	echo -e "\e[31mFirst test failed\e[0m"
	echo -e "\e[31mExpected: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\e[0m"
	echo -e "\e[31mGot:      $output\e[0m"
fi
echo
# the [ is a command (the test command), and it requires spaces around 
# it to be parsed correctly. Without spaces, Bash interprets ["$output" 
# as a single command, leading to the error:
output=$(./megaphone | tr -d '\n')
if [ "$output" = "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ]; then
	echo -e "\e[32mSecond test passed\e[0m"
	echo -e "\e[32mExpected: * LOUD AND UNBEARABLE FEEDBACK NOISE *\e[0m"
	echo -e "\e[32mGot:      $output\e[0m"
else
	echo -e "\e[31mSecond test failed\e[0m"
	echo -e "\e[31mExpected: * LOUD AND UNBEARABLE FEEDBACK NOISE *\e[0m"
	echo -e "\e[31mGot:      $output\e[0m"
fi

echo
output=$(./megaphone Damnit " ! " "Sorry students, I thought this thing was off.")
if [ "$output" = "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." ]; then
	echo -e "\e[32mThird test passed\e[0m"
	echo -e "\e[32mExpected: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\e[0m"
	echo -e "\e[32mGot:      $output\e[0m"
else
	echo -e "\e[31mThird test failed\e[0m"
	echo -e "\e[31mExpected: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\e[0m"
	echo -e "\e[31mGot:      $output\e[0m"
fi
