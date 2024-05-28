class Singleton {
  public:
    static Singleton *Instance(); // gives back a real object!
    static proof(void);           // proof that the object was made
  protected:
    Singleton(); // constructor
  private:
    static Singleton *_singleton;
};

Singleton *Singleton::_singleton = 0;
Singleton *Singleton::Instance() {
    if (_singleton == 0) {
        _singleton = new Singleton;
    } // endif
    return _singleton;
} // end Instance()