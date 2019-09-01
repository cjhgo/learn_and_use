import socket




def create_socket_reuse_port(address,flag):
  s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEPORT,flag)
  s.bind(address)
  s.listen(5)
  return s  
def create_socket_reuse_addr(address,flag,flag2):
  s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
  s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,flag)
  s.bind(address)
  if flag2:
    s.listen(5)
  return s  