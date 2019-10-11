


input={
    "a":1,
    "b":2
}


key="a"
class foo:
    x=input[key]
    def __init__(self):
        print(self.x)


key="b"
f =foo()