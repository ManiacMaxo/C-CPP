import turtle
t = turtle.Pen()
t.speed(0)

side = 300
step = 10

for i in range(int(side/(2*step))):
    for j in range(4):
        if ((i % 2 and j < 2) or (not(i % 2) and j > 1)):
            t.up()
        else:
            t.down()
        t.forward(side)
        t.left(90)
    t.up()
    t.forward(step)
    t.left(90)
    t.forward(step)
    t.right(90)
    t.down()
    side-=2*step
