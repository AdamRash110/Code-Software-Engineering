import turtle

#Set up the screen
screen = turtle.Screen()
screen.title("Pong Game")
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.tracer(0) #Turned off automatic screen updates for a smoother animation

#Left paddle
left_paddle = turtle.Turtle()
left_paddle.shape("square")
left_paddle.color("blue")
left_paddle.shapesize(stretch_wid=6, stretch_len=1) #Created a 6x1 rectangle
left_paddle.penup()
left_paddle.goto(-350, 0)

#Right paddle
right_paddle = turtle.Turtle()
right_paddle.shape("square")
right_paddle.color("red")
right_paddle.shapesize(stretch_wid=6, stretch_len=1) #Created a 6x1 rectangle
right_paddle.penup()
right_paddle.goto(350, 0)

#Ball
ball = turtle.Turtle()
ball.shape("square")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = 0.15
ball.dy = 0.15

#Paddle movements
def left_paddle_up():
    y = left_paddle.ycor()
    if y < 250: #This prevents the ball from moving off the screen
        left_paddle.sety(y + 20)

def left_paddle_down():
    y = left_paddle.ycor()
    if y > -240: #This prevents the ball from moving off the screen
        left_paddle.sety(y - 20)

def right_paddle_up():
    y = right_paddle.ycor()
    if y < 250: #This prevents the ball from moving off the screen
        right_paddle.sety(y + 20)

def right_paddle_down():
    y = right_paddle.ycor()
    if y > -240: #This prevents the ball from moving off the screen
        right_paddle.sety(y - 20)

#Keyboard bindings
screen.listen()
screen.onkey(left_paddle_up, "w")
screen.onkey(left_paddle_down, "s")
screen.onkey(right_paddle_up, "Up")
screen.onkey(right_paddle_down, "Down")

#Main loop of game
while True:
    screen.update()

    #Move the ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    #Ball collision with top and bottom walls
    if ball.ycor() > 290:
        ball.sety(290)
        ball.dy *= -1

    if ball.ycor() < -290:
        ball.sety(-290)
        ball.dy *= -1

    #Ball collision with paddles
    if (ball.xcor() > 340 and ball.xcor() < 350) and (right_paddle.ycor() + 50 > ball.ycor() > right_paddle.ycor() - 50):
        ball.setx(340)
        ball.dx *= -1

    if (ball.xcor() < -340 and ball.xcor() > -350) and (left_paddle.ycor() + 50 > ball.ycor() > left_paddle.ycor() - 50):
        ball.setx(-340)
        ball.dx *= -1

    if ball.xcor() > 390:
        ball.goto(0, 0)
        ball.dx *= -1

    if ball.xcor() < -390:
        ball.goto(0, 0)
        ball.dx *= -1