class Composition {

  public:
    Composition(Compositor *);
    void Repair();

  private:
    Compositor *_compositor;
    Component *_components;
    int _componentCount;
    int _lineWidth;
    int *_lineBreaks;

    int _lineCount;
};

class Compositor {
  public:
    virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[], int component Count, int lineWidth, int breaks[]) = 0;

  protected:
    Compositor();
};

// Strategy 1
class SimpleCompositor : public compositor {

  public:
    SimpleCompositor();

    virtual int Compose(
        Coord natural[], Coord stretch[],
        Coord shrink[], int componentCount,
        int lineWidth, int breaks[]);
};

// Strategy 2
class TeXCompositor : public Compositor {
  public:
    TeXCompositor();

    virtual int Compose(
        Coord natural[], Coord stretch[],
        Coord shrink[], int component Count,
        int lineWidth, int breaks[]);
};

// Strategy 3
class ArrayCompositor : public Compositor public : ArrayCompositor(int interval);

virtual int Compose {
    Coord natural[], Coord stretch[],
    Coord shrink[], int componentCount,
    int lineWidth, int breaks[]);
};

// To instantiate Composition, you pass it the compositor you want to use:

Composition *quick = new Composition(new SimpleCompositor);
Composition *slick = new Composition(new TeXCompositor);
Composition *iconic = new Composition(new ArrayCompositor);