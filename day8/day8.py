from math import lcm

f = open("day8/day8.txt", "r")

directions = "LRRLRLRRLRRRLRLRLRRLRRRLRRRLRRLRRRLRLRLRLRLRLRLRRRLRRLRRRLLLLRRRLRLLLRRRLLRLLRRRLRRRLRLRRLRRRLRRRLLRRRLRLRRRLLRRRLRLLRRRLRRLLRLRLRLRRRLRLLRLRLRRRLRLLRLRLRRRLLRRRLRRLRRRLRLRRLRLRRLRLRRLRRRLLRRRLLLRRRLLRRLRRLRRLRLLRRLRRRLRRLRLRLRRLRRLLLRRLRLRRRLRRRLRRRLLLRLRRRLLRRRLRLLRRRR"

input=[]

def part1():
    curr_ele="AAA"
    count=0
    steps=0

    for line in f:
        input.append(line.split())

    while curr_ele != "ZZZ":
        if count == len(directions):
            count=0

        for i in range(len(input)):
            if curr_ele == input[i][0]:
                curr_line = i
                break

        if directions[count] == 'L':
            curr_ele=input[curr_line][1]
        else:
            curr_ele=input[curr_line][2]
        
        count+=1
        steps+=1

    print(steps)

def part2():
    curr_eles=[]
    ele_indices=[0, 0, 0, 0, 0, 0]
    count=0
    steps=0
    flag=False

    for line in f:
        input.append(line.split())

    for i in range(len(input)):
        if input[i][0][2] == 'A':
            curr_eles.append(input[i][0])

    while len(curr_eles) > 0:
        if count == len(directions):
            count=0

        for j in range(len(curr_eles)):
            for k in range(len(input)):
                if directions[count] == 'L':
                    if input[k][0] == curr_eles[j]:
                        curr_eles[j] = input[k][1]
                        break
                else:
                    if input[k][0] == curr_eles[j]:
                        curr_eles[j] = input[k][2]
                        break                

        count+=1
        steps+=1

        for e in range(len(curr_eles)):
            if curr_eles[e][2] == 'Z' and ele_indices[e] == 0:
                ele_indices[e] = steps

        for i in ele_indices:
            if i==0:
                flag = False
                break

            flag=True

        if flag:
            print(lcm(*ele_indices))
            break

part1()
part2()

