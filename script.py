import random
file = input('give me a name of file ')
with open(file, 'w') as f:
    for i in range(20):
        i = str(i)
        string = 'wall;0;' + i + '\n'
        f.write(string)
        string = 'wall;' + i + ';0\n'
        f.write(string)
        string = 'wall;19;' + i + '\n'
        f.write(string)
        string = 'wall;' + i + ';19\n'
        f.write(string)
    player = 'player;1;1;50;50;50;0\n'
    f.write(player)
    num_monster = input('give me a number of monsters ')
    xp = 5
    yp = 2
    x = y = 2
    for i in range(int(num_monster)):
        if x + xp < 20:
            x += xp
        else:
            xp -= 2
            x -= 2
        if y + yp < 20:
            y += yp
        else:
            yp -= 2
            y -= 2
        moster = 'monster;' + str(x) + ';' + str(y) + ';' + str(x+ xp) + ';' + str(x+ xp) + ';' +  str(y+ xp) + '\n'
        f.write(moster)
        name = input('give me a name of item ')
        bonus = 'item;' + name + ';' + str(x + 1) + ';' + str(y - 1) + ';' + str(random.randint(1, 50)) + ';' + str(random.randint(1, 50)) + ';' + str(random.randint(1, 50)) + '\n'
        f.write(bonus)
        bonus = 'item;' + name + '1' + ';' + str(x - 1) + ';' + str(y + 1) + ';' + str(random.randint(1, 50)) + ';' + str(random.randint(1, 50)) + ';' + str(random.randint(1, 50)) + '\n'
        f.write(bonus)
        
