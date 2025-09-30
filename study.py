print([(x,y,z)
        for x in range(5)
        for y in range(5)
        if x!=y
        for z in range(5)
        if y!=z])