package mod.instance;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;

import javax.swing.JPanel;

import Define.AreaDefine;
import Pack.DragPack;
import bgWork.handler.CanvasPanelHandler;
import mod.IFuncComponent;
import mod.ILinePainter;
import java.lang.Math;

public class AssociationLine extends JPanel
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

	public AssociationLine(CanvasPanelHandler cph) {
		this.setOpaque(false);
		this.setVisible(true);
		this.setMinimumSize(new Dimension(1, 1));
		this.cph = cph;
	}

	@Override
	public void paintComponent(Graphics g) {
		Point fpPrime;
		Point tpPrime;
		renewConnect();
		fpPrime = new Point(fp.x - this.getLocation().x,
				fp.y - this.getLocation().y);
		tpPrime = new Point(tp.x - this.getLocation().x,
				tp.y - this.getLocation().y);
		g.setColor(Color.BLACK);
		g.drawLine(fpPrime.x, fpPrime.y, tpPrime.x, tpPrime.y);

		paintArrow(g, tpPrime);

		System.out.println("AssociationLine now isSelect: " + isSelect);
		if (isSelect == true) {
			paintSelect(g);
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

		// System.out.println("fp.x: " + fp.x);
		// System.out.println("fp.y: " + fp.y);
		// System.out.println("this.getLocation().x: " + this.getLocation().x);
		// System.out.println("this.getLocation().y: " + this.getLocation().y);
		fpPrime = new Point(fp.x - this.getLocation().x,
				fp.y - this.getLocation().y);
		tpPrime = new Point(tp.x - this.getLocation().x,
				tp.y - this.getLocation().y);
		// System.out.println("fpPrime.x: " + fpPrime.x);
		// System.out.println("fpPrime.y: " + fpPrime.y);

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
		System.out.println("clickedArea: " + side);
		System.out.println("fromSide: " + fromSide);
		System.out.println("toSide: " + toSide);

		if ((from == jPanel && fromSide == side) || (to == jPanel && toSide == side)) {
			return true;
		}
		return false;
	}
}
