import tkinter as tk
from tkinter import ttk
from libretranslatepy import LibreTranslateAPI

# Translate API ##########

lt = LibreTranslateAPI("https://translate.argosopentech.com/")

language_data = lt.languages()
language_names = [lang['name'] for lang in language_data]
language_codes = {lang['name']: lang['code'] for lang in language_data}

# App ##########

app = tk.Tk()
app.geometry("700x400")
app.title("Translator")
app.config(bg="white")

app_name = tk.Label(app, text="Translator | مترجم",
                    font="arial 15 bold", bg="white")
app_name.place(x=265, y=0)

# input details

input_lable = tk.Label(app, text="Enter Text",
                       font="arial 13 bold", bg="white")
input_lable.place(x=95, y=45)

input_text = tk.Text(app, font="arial 10 bold",
                     bg="white", height=11, width=30, padx=5)
input_text.place(x=30, y=110)

input_lang = ttk.Combobox(app, width=19, values=language_names)
input_lang.place(x=70, y=80)
input_lang.set("choose input language")
# ---------------------------------------------

# output details

output_lable = tk.Label(app, text="Output", font="arial 13 bold", bg="white")
output_lable.place(x=515, y=45)

output_text = tk.Text(app, font="arial 10", bg="white",
                      height=11, width=30, padx=5)
output_text.place(x=440, y=110)

output_lang = ttk.Combobox(app, width=19, values=language_names)
output_lang.place(x=480, y=80)
output_lang.set("choose output language")
# ---------------------------------------------

# translate button


def translate():
    translated_text = lt.translate(input_text.get(
        "1.0", tk.END), language_codes[input_lang.get()], language_codes[output_lang.get()])
    output_text.delete("1.0", tk.END)
    output_text.insert("1.0", translated_text)


trans_btn = tk.Button(app, text="Translate",
                      font="arial 10 bold", padx=5, command=translate)
trans_btn.place(x=305, y=180)

app.mainloop()
