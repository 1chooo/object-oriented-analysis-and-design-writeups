package mod.instance;

import java.awt.*;

import javax.swing.JPanel;

import Define.AreaDefine;
import Pack.DragPack;
import bgWork.handler.CanvasPanelHandler;
import mod.IFuncComponent;
import mod.ILinePainter;
import java.lang.Math;

public class DependencyLine extends JPanel
        implements IFuncComponent, ILinePainter {
    JPanel from;
    int fromSide;
    Point fp = new Point(0, 0);
    JPanel to;
    int toSide;
    Point tp = new Point(0, 0);
    int arrowSize = 6;
    boolean isSelect = false;
    int selectBoxSize = 5;
    CanvasPanelHandler cph;

    public DependencyLine(CanvasPanelHandler cph) {
        this.setOpaque(false);
        this.setVisible(true);
        this.setMinimumSize(new Dimension(1, 1));
        this.cph = cph;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;
        float[] dashPattern = { 10, 10 }; // 10 pixels drawn, 10 pixels not drawn -> dotted line
        g2d.setStroke(new BasicStroke(
                1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER,
                10, dashPattern, 0));

        Point fpPrime;
        Point tpPrime;
        renewConnect();
        fpPrime = new Point(fp.x - this.getLocation().x,
                fp.y - this.getLocation().y);
        tpPrime = new Point(tp.x - this.getLocation().x,
                tp.y - this.getLocation().y);

        g2d.setColor(Color.BLACK);
        g2d.drawLine(fpPrime.x, fpPrime.y, tpPrime.x, tpPrime.y);
        paintArrow(g2d, tpPrime);
        if (isSelect == true) {
            paintSelect(g2d);
        }
    }

    @Override
    public void reSize() {
        Dimension size = new Dimension(Math.abs(fp.x - tp.x) + 10,
                Math.abs(fp.y - tp.y) + 10);
        this.setSize(size);
        this.setLocation(Math.min(fp.x, tp.x) - 5, Math.min(fp.y, tp.y) - 5);
    }

    @Override
    public void paintArrow(Graphics g, Point point) {
        // TODO Auto-generated method stub
    }

    @Override
    public void setConnect(DragPack dPack) {
        Point mfp = dPack.getFrom();
        Point mtp = dPack.getTo();
        from = (JPanel) dPack.getFromObj();
        to = (JPanel) dPack.getToObj();
        fromSide = new AreaDefine().getArea(from.getLocation(), from.getSize(),
                mfp);
        toSide = new AreaDefine().getArea(to.getLocation(), to.getSize(), mtp);
        renewConnect();
        System.out.println("from side " + fromSide);
        System.out.println("to side " + toSide);
    }

    void renewConnect() {
        try {
            fp = getConnectPoint(from, fromSide);
            tp = getConnectPoint(to, toSide);
            this.reSize();
        } catch (NullPointerException e) {
            this.setVisible(false);
            cph.removeComponent(this);
        }
    }

    Point getConnectPoint(JPanel jp, int side) {
        Point temp = new Point(0, 0);
        Point jpLocation = cph.getAbsLocation(jp);
        if (side == new AreaDefine().TOP) {
            temp.x = (int) (jpLocation.x + jp.getSize().getWidth() / 2);
            temp.y = jpLocation.y;
        } else if (side == new AreaDefine().RIGHT) {
            temp.x = (int) (jpLocation.x + jp.getSize().getWidth());
            temp.y = (int) (jpLocation.y + jp.getSize().getHeight() / 2);
        } else if (side == new AreaDefine().LEFT) {
            temp.x = jpLocation.x;
            temp.y = (int) (jpLocation.y + jp.getSize().getHeight() / 2);
        } else if (side == new AreaDefine().BOTTOM) {
            temp.x = (int) (jpLocation.x + jp.getSize().getWidth() / 2);
            temp.y = (int) (jpLocation.y + jp.getSize().getHeight());
        } else {
            temp = null;
            System.err.println("getConnectPoint fail:" + side);
        }
        return temp;
    }

    @Override
    public void paintSelect(Graphics gra) {
        Point fpPrime;
        Point tpPrime;

        fpPrime = new Point(fp.x - this.getLocation().x,
                fp.y - this.getLocation().y);
        tpPrime = new Point(tp.x - this.getLocation().x,
                tp.y - this.getLocation().y);

        gra.setColor(Color.RED);
        gra.fillRect(fpPrime.x, fpPrime.y, selectBoxSize, selectBoxSize);
        gra.fillRect(tpPrime.x, tpPrime.y, selectBoxSize, selectBoxSize);

        gra.drawLine(fpPrime.x, fpPrime.y, tpPrime.x, tpPrime.y);
    }

    public boolean isSelect() {
        return isSelect;
    }

    public void setSelect(boolean isSelect) {
        this.isSelect = isSelect;
    }

    public boolean checkOnSide(JPanel jPanel, int side) {
        if ((from == jPanel && fromSide == side) || (to == jPanel && toSide == side)) {
            return true;
        }
        return false;
    }
}
