import threading
from time import gmtime, strftime

class _Singleton(type):
    """ A metaclass that creates a Singleton base class when called. """
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(_Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]

class Singleton(_Singleton('SingletonMeta', (object,), {})): pass

class Logger(Singleton):
    def get_iter(self, data):
        return self.value
    def __init__(self, start = 0):
        self.lock = threading.Lock()
        self.value = start
    def increment(self):
        self.lock.acquire()
        try:
            self.value = self.value + 1
            if self.value%1000 == 0 or self.value == 1 or self.value == 10:
                with open('/home/mkoi/mgr/myDig/python_module/debug', 'a') as file:
                    file.write(strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime()) + ", " + str(self.value)+"\n")
        finally:
            self.lock.release()
    def write_log(self, file_path, domain, result):
        self.lock.acquire()
        try:
            with open(file_path, 'a') as f:
                f.write(domain+ " " + result+"\n")
        finally:
            self.lock.release()
    def write_to_log(self, file_path, domain):
        self.write_log(file_path, domain, "TO")
    def write_tf_log(self, file_path, domain):
        self.write_log(file_path, domain, "TF")
    def write_axfr_log(self, file_path, domain):
        self.write_log(file_path, domain, "AXFR answer")
    def write_unknown_log(self, file_path, domain):
        self.write_log(file_path, domain, "unknown")