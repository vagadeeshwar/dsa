# 3 rods - source,auxilliary,destination
# source rod has n disks(with hole at center) of decreasing size from bottom to top
# shift all disks to destination with help of auxilliary rod following the rules:
# 1. move 1 disk at a time 2. at any point, larger disk cannot be put on smaller one

# Use mathematical induction, in fact every recursive alg uses induction in the hood


def tower_of_hanoi(n, source, aux, dest):
    if n == 0:  # Check validity of initial ie base cases
        return  # No disk? Do nothing
    if n == 1:  # One disk? Shift top disk of source to dest
        print(source, dest)
        return
    # Assume that f(n-1) is true ie there exists a way to move 'top n-1' disks from source to dest
    tower_of_hanoi(n - 1, source, dest, aux)  # if so, let's move disks from source to aux rod
    # In this process, the aux rod acts like the dest and the dest rod acts like the aux
    print(source, dest)  # Move the 1 disk(the largest) from source to dest
    tower_of_hanoi(
        n - 1, aux, source, dest
    )  # Now, move back the n-1 disks from aux(acts like the source now) to dest(dest) using source(acts like the aux now)
    # as we know how to move n-1 to the correct place and the 1 disk at dest is equivalent to being empty


# Remember, that we have assumed n-1 with the fact that there is an empty aux and dest rod
# Hence, we must always provide empty aux & dest rods while calling tower_of_hanoi()

n = int(input())
tower_of_hanoi(n, "a", "b", "c")
