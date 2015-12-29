package presentacion.reportes;

import java.util.List;

import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.JasperReport;
import net.sf.jasperreports.engine.data.JRBeanCollectionDataSource;
import net.sf.jasperreports.engine.util.JRLoader;
import net.sf.jasperreports.view.JasperViewer;
import dto.PersonaDTO;

public class ReporteAgenda
{
	private JasperReport reporte;
	private JasperViewer reporteViewer;
	private JasperPrint	reporteLleno;
	
    public ReporteAgenda(List<PersonaDTO> personas)
    {
    	try 
		{
			this.reporte = (JasperReport) JRLoader.loadObjectFromFile( "reportes\\ReporteAgenda.jasper" );
			this.reporteLleno = JasperFillManager.fillReport(this.reporte, null, 
					new JRBeanCollectionDataSource(personas));
		}
		catch( JRException ex ) 
		{
			ex.printStackTrace();
		}
    }       
    
    public void mostrar()
	{
		this.reporteViewer = new JasperViewer(this.reporteLleno);
		this.reporteViewer.setVisible(true);
	}
        
	
}	