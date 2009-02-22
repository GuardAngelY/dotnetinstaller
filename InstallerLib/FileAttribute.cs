using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// A file attribute.
    /// </summary>
    [XmlNoChildren]
    public class FileAttribute : XmlClassImpl
    {
        public FileAttribute()
        {
        }

        #region Attributes
        private string m_name;
        [Description("The name of the file attribute (REQUIRED)")]
        public string name
        {
            get { return m_name; }
            set { m_name = value; }
        }

        private string m_value = null;
        [Description("The value of the file attribute (OPTIONAL)")]
        public string value
        {
            get { return m_value; }
            set { m_value = value; }
        }

        public string data
        {
            get
            {
                return (m_value != null) 
                    ? string.Format("{0}\0", m_value.Trim('\0')) 
                    : null;
            }
        }

        #endregion

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "fileattribute"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("name", m_name);
            if (m_value != null)
                e.XmlWriter.WriteAttributeString("value", m_value);

            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["name"] != null)
                m_name = e.XmlElement.Attributes["name"].InnerText;

            if (e.XmlElement.Attributes["value"] != null)
                m_value = e.XmlElement.Attributes["value"].InnerText;
        }

        public override string ToString()
        {
            return m_name;
        }
    }
}