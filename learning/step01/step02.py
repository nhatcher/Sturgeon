#!/usr/bin/python
# -*- coding: utf-8 -*-
 
import sys
from PySide.QtCore import *
from PySide.QtGui import *
 
class Form(QDialog):
   
  def __init__(self, parent=None):
    super(Form, self).__init__(parent)
    # Create widgets
    self.label = QLabel("Enter a small integer")
    self.edit = QLineEdit()
    self.button = QPushButton("Show result")
    self.result_label = QLabel();
    # Create layout and add widgets
    layout = QVBoxLayout()
    layout.addWidget(self.label)
    layout.addWidget(self.edit)
    layout.addWidget(self.button)
    layout.addWidget(self.result_label)
    # Set dialog layout
    self.setLayout(layout)
    # Add button signal to greetings slot
    self.button.clicked.connect(self.compute)
       
  # Computes the result
  def compute(self):
    N = int(self.edit.text())
    st = "The squares and cubes of the first "+str(N)+" numbers are:\n"
    for i in range(1,N+1):
      st += "Number: "+str(i)+". Square: "+str(i**2)+". Cube: "+str(i**3)+"\n"
    self.result_label.setText(st)
 
 
if __name__ == '__main__':
  app = QApplication(sys.argv)
  form = Form()
  form.show()
  sys.exit(app.exec_())