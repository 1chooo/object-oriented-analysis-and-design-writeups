class Equipment {
  public:
    virtual ~Equipment();
    const char *Name() { return _name; }

    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency Discountprice();
    virtual virtual virtual Virtual void Add(Equipment *);
    Virtual void Remove(Equipment *);

  protected:
    Equipment(const char *);

  private:
    const char *_name;
    Iterator<Equipment *> *Createlterator();
}

class FloppyDisk : public Equipment {

  public:
    FloppyDisk(const char *);
    virtual ~FloppyDisk();
    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency Discountprice();
};

class CompositeEquipment : public Equipment {

  public:
    virtual ~CompositeEquipment();
    virtual Watt Power();
    virtual Currency NetPrice();
    virtual Currency Discountprice();
    virtual void Add(Equipment *);
    virtual void Remove(Equipment *);
    virtual Iterator<Equipment *> *Createlterator();

  protected:
    CompositeEquipment(const char *);

  private:
    List<Equipment *> _equipment;
};

class Chassis : public compositeEquipment {
  public:
    Chassis(const char *);
    virtual ~Chassis();
    virtual Watt Power();
    virtual Currency Netprice();
    virtual Currency Discountprice();
};

Cabinet *cabinet = new Cabinet("PC Cabinet");
Chassis *chassis = new Chassis("PC Chassis");
cabinet->Add(chassis);
Bus *bus = new Bus("MCA Bus");
bus->Add(new Card("l6Mbs Token Ring");
chassis->Add(bus);
chassis->Add(new FloppyDisk("3.5in Floppy“);
cout << "The net price is " ? chassis->NetPrice() ? end