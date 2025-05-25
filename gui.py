import ctypes
from tkinter import *

# Load the DLL
lib = ctypes.CDLL('./calc.dll')
lib.calculate.argtypes = [ctypes.c_char_p]
lib.calculate.restype = ctypes.c_double

# GUI Setup
root = Tk()
root.title("C++ Basic Calculator")
root.geometry("370x410")
root.configure(bg="#2e2e2e")

expression = ""

def press(key):
    global expression
    if key == 'C':
        expression = ""
        equation.set("")
    elif key == '=':
        try:
            result = lib.calculate(expression.encode('utf-8'))
            equation.set(str(result))
            expression = str(result)
        except:
            equation.set("Error")
            expression = ""
    else:
        expression += key
        equation.set(expression)

# Display (non-editable style)
equation = StringVar()
display = Label(root, textvariable=equation, font=('Consolas', 28), bg="white", fg="black",
                anchor='e', relief=SUNKEN, bd=5, height=2, width=17)
display.grid(row=0, column=0, columnspan=4, padx=10, pady=15)

# Buttons
button_color = "#4e4e4e"
text_color = "white"
highlight_color = "#ff9500"  # for '=' and 'C'

buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', '.', 'C', '+',
    '=', 
]

row = 1
col = 0
for b in buttons:
    color = highlight_color if b in ['=', 'C'] else button_color
    btn = Button(root, text=b, font=('Arial', 12), bg=color, fg=text_color, width=8, height=2,
                 command=lambda x=b: press(x), bd=0, relief=RAISED)
    btn.grid(row=row, column=col, padx=5, pady=5)
    col += 1
    if col > 3:
        col = 0
        row += 1

root.mainloop()
