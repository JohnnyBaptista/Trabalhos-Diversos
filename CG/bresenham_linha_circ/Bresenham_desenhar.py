# imports every file form tkinter and tkinter.ttk
from tkinter import *

_author_ = "Vedovotto"

class Circ:
    #implementar
    pass

class Linha:
    def __init__(self, window, canvas):
        self.window = window
        self.canvas = canvas
        self.new_line = True

    def desenha_linha(self, event):
        if self.new_line:
            self.x1 = event.x
            self.y1 = event.y
            self.new_line = False
        else:
            self.x2 = event.x
            self.y2 = event.y
            self.bresenham(self.x1, self.y1, self.x2, self.y2)
            self.new_line = True

    def bresenham(self, x0, y0, x1, y1):
        # "Bresenham's line algorithm"
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        x, y = x0, y0
        sx = -1 if x0 > x1 else 1
        sy = -1 if y0 > y1 else 1
        if dx > dy:
            err = dx / 2
            while x != x1:
                self.put_pixel(x, y)
                err -= dy
                if err < 0:
                    y += sy
                    err += dx
                x += sx
        else:
            err = dy / 2.0
            while y != y1:
                self.put_pixel(x, y)
                err -= dx
                if err < 0:
                    x += sx
                    err += dy
                y += sy        
        self.put_pixel(x, y)


    def put_pixel(self, x, y):
        self.canvas.create_polygon((x,y), outline="#476042",
            fill='yellow', width=0.5)


class SistemaCentral:
    def __init__(self, master=None):
        self.master = master

    def op1(self):
        self.window = Toplevel(master)
        self.txt = Label(self.window, text="Clique em dois pontos para desenhar semirretas ;)")
        self.txt.pack()
        self.canvas = Canvas(self.window, width=400,
                             height=400, bg="black", cursor="cross")
        self.canvas.pack()
        self.linha = Linha(self.window, self.canvas)
        self.window.bind("<1>", self.linha.desenha_linha)

    def op2(self):
        window = Toplevel(master)
    

if __name__ == "__main__":

    # object of class Tk, resposible for creating
    # a tkinter toplevel window
    master = Tk()
    sys = SistemaCentral(master)
    master.title("Trabalho CG - Vedovotto")
    txt = Label(master, text="Escolha uma opção para desenhar:")
    txt.pack()
    # This will bind arrow keys to the tkinter
    # toplevel which will navigate the image or drawing
    button1 = Button(master, text="Reta", command=sys.op1)
    button1.pack()
    button2 = Button(master, text="Circulo", command=sys.op2)
    button2.pack()

    # Infnite loop breaks only by interrupt
    mainloop()
