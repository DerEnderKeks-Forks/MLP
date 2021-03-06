#include "XYPlot.h"


XYPlot::XYPlot( const char *channelName /*= NULL*/, Print &rDestination )
  : Plot(F("XYPLOT"), channelName, rDestination)
{

}

XYPlot::XYPlot( const __FlashStringHelper *channelName, Print &rDestination )
  : Plot(F("XYPLOT"), channelName, rDestination)
{

}

void XYPlot::SendData(const __FlashStringHelper * seriesName, float *xValues, float *yValues, unsigned NumberOfValues, int nDecimalPlaces, const char * seriesProperties = NULL)
{
  SendHeader_Data();
  m_rDestination.print(seriesName);
  SendData(xValues, yValues, NumberOfValues, nDecimalPlaces, seriesProperties);
}

void XYPlot::SendData(const char * seriesName, float *xValues, float *yValues, unsigned NumberOfValues, int nDecimalPlaces, const char * seriesProperties = NULL)
{
  SendHeader_Data();
  m_rDestination.print(seriesName);
  SendData(xValues, yValues, NumberOfValues, nDecimalPlaces, seriesProperties);
}

void XYPlot::SendData(float *xValues, float *yValues, unsigned NumberOfValues, int nDecimalPlaces, const char * seriesProperties = NULL)
{
  SendSeriesProperties(seriesProperties);
  while (NumberOfValues--)
  {
    m_rDestination.print(*xValues++, nDecimalPlaces);
    m_rDestination.print('|');
    m_rDestination.print(*yValues++, nDecimalPlaces);
    if (NumberOfValues != 0)
    {
      m_rDestination.print('|');
    }
  }
  SendDataTail();
}