#!/usr/bin/env python
# coding: utf-8

import open3d as o3d
import numpy as np
import os

mesh = o3d.io.read_triangle_mesh("../../TestData/test_mesh.ply")
connected_components = mesh.identically_colored_connected_components()

res_file = open("results.txt","w")
for row in range(len(connected_components)):
        for vertex in connected_components[row]:
            res_file.write(str(vertex)+' ')
        res_file.write("\n")
res_file.close()





