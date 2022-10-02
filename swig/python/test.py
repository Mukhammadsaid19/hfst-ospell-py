import swig_example
swig_example.swig_example_hello()

tr = swig_example.createTransducer("/home/place2play/swig/swig-example/swig/python/iuzbek+.hfst")
swig_example.lookup(tr, "endi")
# swig_example.link_liba_hello("/home/place2play/swig/swig-example/swig/python/iuzbek+.hfst")