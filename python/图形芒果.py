import turtle
 
t = turtle.Turtle()
t.speed(0)
t.color("white")
 
def mango(x, y):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.begin_fill()
    for i in range(36):
        t.forward(20)
        t.right(10)
    t.end_fill()
 
for i in range(0, 250, 25):
    for j in range(0, 250, 25):
        if (i + j) % 50 == 0:
            mango(i-250, j-250)
            
turtle.done()