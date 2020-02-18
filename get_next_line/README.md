## get_next_line
<div>C programming basics</div>
<div style="text-align:justifuy"> In this project, I had to develop a function in which when I call it with these parameters (int fd, char **buf), the function should fill the pointer buf content, with the next line of the file with fd file descriptor.</div>
<br>
<br>
<div style="text-align:justifuy"> What I learned in this project was mainly how to control memory leak, how to avoid it, and how to use commands like 'leaks' or 'valgrind'. In addition, I had to manage with static variables because when you are reading a file you get n characters of it, so when you get the '\n' char (that marks the end of the line) in most cases you have a surplus after endline so you must save it for the next call.</div>

## How to use

<div style="text-align:justifuy">This function is really simple to use, only run this command:</div>
<br>
<code>gcc get_*.c your_test_program.c</code>

#### These all files were written by me, Carlos Lostao.
