import matplotlib.pyplot as plt
import matplotlib.patches as patches

vehicle_length = 40
vehicle_width = 18
near_zone = 10

car_x = 40
car_y = 40

fig, ax = plt.subplots()
ax.set_xlim(0, 120)
ax.set_ylim(0, 120)

car_img = plt.imread("car.png")

# Draw car image
ax.imshow(
    car_img,
    extent=(car_x, car_x + vehicle_length,
            car_y, car_y + vehicle_width)
)

# Highlight overlay (initially invisible)
inside_highlight = patches.Rectangle(
    (car_x+8, car_y+3),
    vehicle_length-14,
    vehicle_width-6,
    facecolor='red',
    alpha=0.3,     # transparency (light red)
    visible=False
)

ax.add_patch(inside_highlight)

# Draw near zone
near = patches.Rectangle(
    (car_x - near_zone,
     car_y - near_zone),
    vehicle_length + 2*near_zone,
    vehicle_width + 2*near_zone,
    edgecolor='orange',
    fill=False,
    linewidth=2
)

ax.add_patch(near)

def on_move(event):
    if event.xdata is None or event.ydata is None:
        return

    x = event.xdata
    y = event.ydata

    car_x_min = car_x
    car_x_max = car_x + vehicle_length
    car_y_min = car_y
    car_y_max = car_y + vehicle_width

    if (car_x_min <= x <= car_x_max and
        car_y_min <= y <= car_y_max):

        zone = "INSIDE VEHICLE"
        inside_highlight.set_visible(True)
        near.set_edgecolor("red")

    elif (car_x_min - near_zone <= x <= car_x_max + near_zone and
          car_y_min - near_zone <= y <= car_y_max + near_zone):

        zone = "NEAR VEHICLE"
        inside_highlight.set_visible(False)
        near.set_edgecolor("yellow")

    else:
        zone = "OUTSIDE"
        inside_highlight.set_visible(False)
        near.set_edgecolor("orange")

    fig.canvas.draw_idle()

    print(f"Pointer: ({round(x,2)}, {round(y,2)}) → {zone}")

fig.canvas.mpl_connect('motion_notify_event', on_move)

plt.title("Vehicle Zone Detection Simulation")
plt.grid()
plt.show()