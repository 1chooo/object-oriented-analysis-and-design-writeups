class Graphic {
  public:
    virtual ~Graphic();

    virtual void Draw(const Point &at) = 0;
    virtual void HandleMouse(Event &event) = 0;

    virtual const point &GetExtent() = 0;

    virtual void Load(istream &from) = 0;
    virtual void Save(ostream &to) = 0;

  protected:
    Graphic();
};

class Image : public Graphic {

  public:
    Image(const char *file); // loads image from a file
    virtual ~Image();

    virtual void Draw(const point &at);
    virtual void HandleMouse(Event &event);

    virtual const point &GetExtent();
    virtual virtual private : I I...

                              void
                              Load(istream &from);
    void Save(ostream &to);
};

// Imageproxy has the same interface as Image:
class Imageproxy : public Graphic {
  public:
    ImageProxy(const char *imageFile);
    virtual ~ImageProxy();

    virtual void Draw(const point &at);
    virtual void HandleMouse(Event &event);

    virtual const point &GetExtent();

    virtual void Load(istream &from);
    virtual void Save(ostream &to);

  protected:
    Image *GetImage();

  private:
    Image *_image;
    Point _extent;
    char *_fileName;
};

ImageProxy::Imageproxy(const char *fileName) {
    _fileName = strdup(fileName);
    _extent = Point::Zero; //  don't know extent yet _image = 0;
}

Image *Imageproxy : : GetImage() {
    if (_image == 0) {
        _image = new Image(_fileName);
    }
    return _image;
}

void ImageProxy::Draw(const point &at) {
    GetImage()->Draw(at);
}

// Finally, suppose we have a class TextDocument that can contain Graphic objects:
class TextDocument {
  public:
    TextDocument();

    void Insert(Graphic *);
    // ...
};

// We can insert an ImageProxy into a text document like this:
TextDocument *text = new TextDocument;
// ...
text->Insert(new ImageProxy("anImageFileName");