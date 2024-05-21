# Start Turtle Drawing
import turtle

# Blue Olympic Ring
a_turtle = turtle.Turtle()
a_turtle.penup() 
a_turtle.pensize(5) 
a_turtle.color("blue")
a_turtle.goto(-110,25)
a_turtle.pendown()
a_turtle.circle(50)
a_turtle.end_fill()

# Black Olympic Ring
a_turtle = turtle.Turtle()
a_turtle.penup() 
a_turtle.pensize(5)
a_turtle.color("black")
a_turtle.goto(0,25) 
a_turtle.pendown() 
a_turtle.circle(50) 
a_turtle.end_fill()

# Red Olympic Ring
a_turtle = turtle.Turtle()
a_turtle.penup() 
a_turtle.pensize(5) 
a_turtle.color("red")
a_turtle.goto(110,25) 
a_turtle.pendown() 
a_turtle.circle(50) 
a_turtle.end_fill()

# Yellow Olympic Ring
a_turtle = turtle.Turtle()
a_turtle.penup() 
a_turtle.pensize(5) 
a_turtle.color("gold")
a_turtle.goto(-55,-25) 
a_turtle.pendown() 
a_turtle.circle(50) 
a_turtle.end_fill()

# Green Olympic Ring
a_turtle = turtle.Turtle()
a_turtle.penup() 
a_turtle.pensize(5) 
a_turtle.color("green")
a_turtle.goto(55,-25) 
a_turtle.pendown() 
a_turtle.circle(50) 
a_turtle.end_fill()

# End Turtle Drawing
turtle.done()