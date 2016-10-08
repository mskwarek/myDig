from ctypes import cdll
import ctypes
import time
import database

class Vector(object):
    lib = cdll.LoadLibrary('/home/mkoi/mgr/myDig/build/lib/libAxfrLib.so')
    lib.axfrLookup_getDumbVector.restype = ctypes.c_void_p
    lib.axfrLookup_getDumbVector.argtypes = []
    #lib.delete_vector.restype = None
    #lib.delete_vector.argtypes = [c_void_p]
    lib.axfrLookup_getDumbSize.restype = ctypes.c_int
    lib.axfrLookup_getDumbSize.argtypes = [ctypes.c_void_p]
    lib.axfrLookup_get_to_return.restype = ctypes.c_char_p
    lib.axfrLookup_get_to_return.argtypes = [ctypes.c_void_p, ctypes.c_int]

    def __init__(self):
        self.vector = Vector.lib.axfrLookup_getDumbVector()
        Vector.lib.axfrLookup_fillWithData(self.vector)
    def __getitem__(self, i):
        if 0 <= i < len(self):
            return self.getitem_cb(i)
        raise IndexError('Vector index out of range')
    def __len__(self):
        return self.getlen_cb()
    def __repr__(self):
        return '[{}]'.format(', '.join(self[i] for i in range(len(self))))


    def getlen_cb(self):
        return Vector.lib.axfrLookup_getDumbSize(self.vector)
    def getitem_cb(self, i):
        return Vector.lib.axfrLookup_get_to_return(self.vector, i)

class axfrVector(Vector):
    def __init__(self, lookup):
        self.lookup = lookup
    def getlen_cb(self):
        return Vector.lib.axfrLookup_getSizeOfReturnedData(self.lookup)
    def getitem_cb(self, i):
        return Vector.lib.axfrLookup_getReturnedDomain(self.lookup, i)
    
    
class axfrLookup(object):
    lib = cdll.LoadLibrary('/home/mkoi/mgr/myDig/build/lib/libAxfrLib.so')
    
    def __init__(self):
        self.obj = self.lib.axfrLookup_new()
    def performLookup(self, domain, ns):
        self.lib.axfrLookup_performLookup(self.obj, domain, ns)
        print "udaoo sie"
    def getResult(self, domain, ns):
        self.lib.axfrLookup_performLookup(self.obj, domain, ns)
        print "after perform"
        self.lib.axfrLookup_getReturnedDomains.restype = ctypes.POINTER(ctypes.c_char_p * self.lib.axfrLookup_getSizeOfReturnedData(self.obj))
        dupa = self.lib.axfrLookup_getReturnedDomains(self.obj)
        print dupa
        #lib.print_data(dupa)
    def destroy(self):
        self.lib.axfrLookup_destroy(self.obj)
            
def perform_lookup(in_list):
    x = axfrLookup()
    print "dziala", in_list[0], in_list[1]
    x.getResult(in_list[0], in_list[1])
    x.destroy()
    

def start_new_process(domain, ns):
    p = Process(target=perform_lookup, args=(domain, ns))
    p.start()
    processes.append(p)
    
from multiprocessing import Process, Queue, Lock
import multiprocessing
import threading

def log_result(result):
    print "result", result
    
def process_lookup(input_list):
    for i in range(len(input_list)):
        pool = multiprocessing.Pool(None)
        try:
            pool.apply_async(perform_lookup, args = (input_list[i], ), callback = log_result)
            i+=1
        except:
            time.sleep(5)
            #continue
        pool.close()
        pool.join()
        
def main_scan():
    input_list = [line.rstrip('\n').split(' ') for line in open('/home/mkoi/mgr/myDig/python_module/inputData')]
    #process_lookup(input_list)
    
    db = database.Psql("credentials.json")
    db.readCredentials()
    db.openConnection()
    
    hosts = column(input_list, 0)
    #print hosts
    start = time.time()
    print db.insertDomainList(hosts)
    db.commitTransaction()
    end = time.time()
    print end-start
    db.closeConnection()
    
    
if __name__ == '__main__':
    #main_scan()
    x = axfrLookup()
    x.dumbDataInt()
    
