import turtle

path = [(-25, 156.25), (-37.5, 200), (-47.5, 118.75), (-130, 125),
        (-175, 143.75), (-207.5, 218.75), (-625, 218.75), (-500, 146.25),
        (-462.5, 108.75), (-437.5, 43.75), (-432.5, 3.75), (-440, -31.25),
        (-207.5, -41.25), (-100, -83.75), (-37.5, -143.75), (0, -218.75),
        (37.5, -143.75), (100, -83.75), (207.5, -41.25), (440, -31.25),
        (432.5, 3.75), (437.5, 43.75), (462.5, 108.75), (500, 146.25),
        (625, 218.75), (207.5, 218.75), (175, 143.75), (130, 125),
        (47.5, 118.75), (37.5, 200), (25, 156.25), (0, 156.25)]

turtle.hideturtle()
turtle.bgcolor("#555")
turtle.setup(1400, 600)

start = (0, 156.25)

turtle.speed(2)


def draw_face(path, start):
    turtle.penup()
    turtle.goto(start)
    turtle.pendown()
    turtle.color("#000")
    turtle.begin_fill()

    for i in range(len(path)):
        x, y = path[i]
        turtle.goto(x, y)

    turtle.end_fill()


draw_face(path, start)
turtle.mainloop()
