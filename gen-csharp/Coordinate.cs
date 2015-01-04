/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;


#if !SILVERLIGHT
[Serializable]
#endif
public partial class Coordinate : TBase
{
  private double _lon;
  private double _lat;

  public double Lon
  {
    get
    {
      return _lon;
    }
    set
    {
      __isset.lon = true;
      this._lon = value;
    }
  }

  public double Lat
  {
    get
    {
      return _lat;
    }
    set
    {
      __isset.lat = true;
      this._lat = value;
    }
  }


  public Isset __isset;
  #if !SILVERLIGHT
  [Serializable]
  #endif
  public struct Isset {
    public bool lon;
    public bool lat;
  }

  public Coordinate() {
  }

  public void Read (TProtocol iprot)
  {
    TField field;
    iprot.ReadStructBegin();
    while (true)
    {
      field = iprot.ReadFieldBegin();
      if (field.Type == TType.Stop) { 
        break;
      }
      switch (field.ID)
      {
        case 1:
          if (field.Type == TType.Double) {
            Lon = iprot.ReadDouble();
          } else { 
            TProtocolUtil.Skip(iprot, field.Type);
          }
          break;
        case 2:
          if (field.Type == TType.Double) {
            Lat = iprot.ReadDouble();
          } else { 
            TProtocolUtil.Skip(iprot, field.Type);
          }
          break;
        default: 
          TProtocolUtil.Skip(iprot, field.Type);
          break;
      }
      iprot.ReadFieldEnd();
    }
    iprot.ReadStructEnd();
  }

  public void Write(TProtocol oprot) {
    TStruct struc = new TStruct("Coordinate");
    oprot.WriteStructBegin(struc);
    TField field = new TField();
    if (__isset.lon) {
      field.Name = "lon";
      field.Type = TType.Double;
      field.ID = 1;
      oprot.WriteFieldBegin(field);
      oprot.WriteDouble(Lon);
      oprot.WriteFieldEnd();
    }
    if (__isset.lat) {
      field.Name = "lat";
      field.Type = TType.Double;
      field.ID = 2;
      oprot.WriteFieldBegin(field);
      oprot.WriteDouble(Lat);
      oprot.WriteFieldEnd();
    }
    oprot.WriteFieldStop();
    oprot.WriteStructEnd();
  }

  public override string ToString() {
    StringBuilder sb = new StringBuilder("Coordinate(");
    sb.Append("Lon: ");
    sb.Append(Lon);
    sb.Append(",Lat: ");
    sb.Append(Lat);
    sb.Append(")");
    return sb.ToString();
  }

}

