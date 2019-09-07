import turtle
t = turtle.Pen()
t.speed(0)

radius = 250
radius2 = radius/3

def drawPetal(t, radius):
    heading = t.heading()
    t.circle(radius, 60)
    t.lt(120)
    t.circle(radius, 60)
    t.setheading(heading)

def drawSmallPetal(t, radius):
    heading = t.heading()
    t.circle(radius, 65)
    t.lt(120)
    t.fd(radius/5)
    t.rt(120)
    t.fd(radius/5)
    t.lt(120)
    t.circle(radius, 65)
    t.setheading(heading)

t.pencolor("green")
for _ in range(12):
    drawPetal(t, radius)
    t.left(360 / 12)

t.pencolor("red")
t.home()
for _ in range(7):
    drawSmallPetal(t, radius2)
    t.left(360 / 7)

t.hideturtle()
