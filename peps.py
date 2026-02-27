import sys
import math
import random
from PyQt5.QtWidgets import QGraphicsRectItem, QApplication, QWidget, QVBoxLayout, QLabel
from PyQt5.QtCore import QTimer
import pyqtgraph as pg

# ---------------- CONFIG ----------------
OUTER_HALF = 5.0     # 100 m² → side 10 → half 5
INNER_HALF = 2.5     # 25 m² → side 5 → half 2.5

ANTENNA_1 = (1, 0)
ANTENNA_2 = (-2, 0)

LIGHT_RED = (255, 200, 200)
NORMAL_BG = (10, 10, 10)   # optional dark theme

# ---------------------------------------

class FobTrackingGUI(QWidget):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("Smart Key – Fob Tracking")
        self.setGeometry(200, 100, 700, 700)
        layout = QVBoxLayout()
        self.setLayout(layout)

        # Plot
        self.plot = pg.PlotWidget()
        self.plot.setAspectLocked(True)
        self.plot.setXRange(-6, 6)
        self.plot.setYRange(-6, 6)
        self.plot.showGrid(x=True, y=True)
        self.plot.setBackground(NORMAL_BG)
        layout.addWidget(self.plot)

        # Labels
        self.info = QLabel()
        self.info.setStyleSheet("font-size: 14px;")
        layout.addWidget(self.info)

        self.draw_zones()
        self.draw_antennas()

        # Fob point
        self.fob = self.plot.plot([], [], pen=None,
                                  symbol='o',
                                  symbolSize=14,
                                  symbolBrush='r')

        # Timer (1 second)
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_fob)
        self.timer.start(1000)
    def draw_zones(self):
        outer = QGraphicsRectItem(-OUTER_HALF, -OUTER_HALF,
                                  OUTER_HALF * 2, OUTER_HALF * 2)
        outer.setPen(pg.mkPen('y', width=2))
        self.plot.addItem(outer)

        inner = QGraphicsRectItem(-INNER_HALF, -INNER_HALF,
                                  INNER_HALF * 2, INNER_HALF * 2)
        inner.setPen(pg.mkPen('g', width=2))
        self.plot.addItem(inner)


    def draw_antennas(self):
        self.plot.plot([ANTENNA_1[0]], [ANTENNA_1[1]],
                       pen=None, symbol='t', symbolSize=18,
                       symbolBrush='b')
        self.plot.plot([ANTENNA_2[0]], [ANTENNA_2[1]],
                       pen=None, symbol='t', symbolSize=18,
                       symbolBrush='b')

    def update_fob(self):
        # Simulated movement (replace with real data)
        x = random.uniform(-6, 6)
        y = random.uniform(-6, 6)

        self.fob.setData([x], [y])

        d1 = math.dist((x, y), ANTENNA_1)
        d2 = math.dist((x, y), ANTENNA_2)

        if abs(x) <= INNER_HALF and abs(y) <= INNER_HALF:
            zone = "INNER ZONE (25 m²)"
            self.plot.setBackground(LIGHT_RED)

        elif abs(x) <= OUTER_HALF and abs(y) <= OUTER_HALF:
            zone = "OUTER ZONE (100 m²)"
            self.plot.setBackground(NORMAL_BG)
        else:
            zone = "OUTSIDE ZONE"
            self.plot.setBackground(NORMAL_BG)
        self.info.setText(
            f"Fob Position: ({x:.2f}, {y:.2f})\n"
            f"Distance to Antenna 1 (2m): {d1:.2f} m\n"
            f"Distance to Antenna 2 (3m): {d2:.2f} m\n"
            f"Zone: {zone}"
        )

# ---------------- RUN ----------------
if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = FobTrackingGUI()
    win.show()
    sys.exit(app.exec_())

