import matplotlib.pyplot as plt
import matplotlib.patches as patches

vehicle_length = 40
vehicle_width = 18
near_zone = 10

fig, ax = plt.subplots()
ax.set_xlim(0, 120)
ax.set_ylim(0, 120)

car_img = plt.imread("car.png")
# vehicle = patches.Rectangle(
#     (-vehicle_length/2, -vehicle_width/2),
#     vehicle_length,
#     vehicle_width,
#     edgecolor='blue',
# #     facecolor='lightblue'
# )
# Draw car image
ax.imshow(
    car_img,
    extent=(40, 40 + vehicle_length,
            40, 40 + vehicle_width)
)

# Draw near zone
near = patches.Rectangle(
    (40 - near_zone,
     40 - near_zone),
    vehicle_length + 2*near_zone,
    vehicle_width + 2*near_zone,
    edgecolor='orange',
    fill=False,
    linestyle='--'
)

ax.add_patch(near)

def on_move(event):
    if event.xdata is None or event.ydata is None:
        return

    x = event.xdata
    y = event.ydata

    car_x_min = 50
    car_x_max = 40 + vehicle_length -5
    car_y_min = 40+3
    car_y_max = 40 + vehicle_width -3

    if (car_x_min <= x <= car_x_max and
        car_y_min <= y <= car_y_max):
        zone = "INSIDE VEHICLE"
        vehicle = patches.Rectangle(
            (-vehicle_length/2, -vehicle_width/2),
            vehicle_length,
            vehicle_width,
            edgecolor='blue',
            facecolor='lightblue'
        )

    elif (car_x_min - near_zone <= x <= car_x_max + near_zone and
          car_y_min - near_zone <= y <= car_y_max + near_zone):
        zone = "NEAR VEHICLE"

    else:
        zone = "OUTSIDE"

    print(f"Pointer: ({round(x,2)}, {round(y,2)}) → {zone}")

fig.canvas.mpl_connect('motion_notify_event', on_move)

plt.title("Vehicle Zone Detection Simulation")
plt.grid()
plt.show()