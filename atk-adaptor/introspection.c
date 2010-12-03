
/*
 * This file has been auto-generated from the introspection data available
 * in the at-spi2-core repository. The D-Bus procol is defined in this
 * repository, which can be found at:
 *
 * http://download.gnome.org/sources/at-spi2-core/0.1/
 *
 * DO NOT EDIT.
 */


const char *spi_org_a11y_atspi_Accessible = 
"<interface name=\"org.a11y.atspi.Accessible\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"name\" type=\"s\" />"
""
"  <property access=\"read\" name=\"description\" type=\"s\" />"
""
"  <property access=\"read\" name=\"parent\" type=\"(so)\">"
"    "
"  </property>"
""
"  <property access=\"read\" name=\"childCount\" type=\"i\" />"
""
"  <method name=\"GetChildAtIndex\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetChildren\">"
"    <arg direction=\"out\" type=\"a(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetIndexInParent\">"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetRelationSet\">"
"    <arg direction=\"out\" type=\"a(ua(so))\" />"
"    "
"  </method>"
""
"  <method name=\"GetRole\">"
"    <arg direction=\"out\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GetRoleName\">"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetLocalizedRoleName\">"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetState\">"
"    <arg direction=\"out\" type=\"au\" />"
"    "
"  </method>"
""
"  <method name=\"GetAttributes\">"
"    <arg direction=\"out\" type=\"a{ss}\" />"
"    "
"  </method>"
""
"  <method name=\"GetApplication\">"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Action = 
"<interface name=\"org.a11y.atspi.Action\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"nActions\" type=\"i\" />"
""
"  <method name=\"GetDescription\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetName\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetKeyBinding\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetActions\">"
"    <arg direction=\"out\" name=\"index\" type=\"a(sss)\" />"
"    "
"  </method>"
""
"  <method name=\"DoAction\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Application = 
"<interface name=\"org.a11y.atspi.Application\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"toolkitName\" type=\"s\" />"
""
"  <property access=\"read\" name=\"version\" type=\"s\" />"
""
"  <property access=\"read\" name=\"id\" type=\"i\" />"
""
"  <method name=\"GetLocale\">"
"    <arg direction=\"in\" name=\"lctype\" type=\"u\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetApplicationBusAddress\">"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Collection = 
"<interface name=\"org.a11y.atspi.Collection\" version=\"0.1.7\">"
""
"  <method name=\"GetMatches\">"
"    <arg direction=\"in\" name=\"rule\" type=\"(auuasuauusub)\" />"
"    "
"    <arg direction=\"in\" name=\"sortby\" type=\"u\" />"
"    <arg direction=\"in\" name=\"count\" type=\"i\" />"
"    <arg direction=\"in\" name=\"traverse\" type=\"b\" />"
"    <arg direction=\"out\" type=\"a(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetMatchesTo\">"
"    <arg direction=\"in\" name=\"current_object\" type=\"o\" />"
"    "
"    <arg direction=\"in\" name=\"rule\" type=\"(auuasuauusub)\" />"
"    "
"    <arg direction=\"in\" name=\"sortby\" type=\"u\" />"
"    <arg direction=\"in\" name=\"tree\" type=\"u\" />"
"    <arg direction=\"in\" name=\"recurse\" type=\"b\" />"
"    <arg direction=\"in\" name=\"count\" type=\"i\" />"
"    <arg direction=\"in\" name=\"traverse\" type=\"b\" />"
"    <arg direction=\"out\" type=\"a(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetMatchesFrom\">"
"    <arg direction=\"in\" name=\"current_object\" type=\"o\" />"
"    "
"    <arg direction=\"in\" name=\"rule\" type=\"(auuasuauusub)\" />"
"    "
"    <arg direction=\"in\" name=\"sortby\" type=\"u\" />"
"    <arg direction=\"in\" name=\"tree\" type=\"u\" />"
"    <arg direction=\"in\" name=\"count\" type=\"i\" />"
"    <arg direction=\"in\" name=\"traverse\" type=\"b\" />"
"    <arg direction=\"out\" type=\"a(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetActiveDescendant\">"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Component = 
"<interface name=\"org.a11y.atspi.Component\" version=\"0.1.7\">"
""
"  <method name=\"Contains\">"
"    <arg direction=\"in\" name=\"x\" type=\"i\" />"
"    <arg direction=\"in\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coord_type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetAccessibleAtPoint\">"
"    <arg direction=\"in\" name=\"x\" type=\"i\" />"
"    <arg direction=\"in\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coord_type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetExtents\">"
"    <arg direction=\"in\" name=\"coord_type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"(iiii)\" />"
"    "
"  </method>"
""
"  <method name=\"GetPosition\">"
"    <arg direction=\"in\" name=\"coord_type\" type=\"u\" />"
"    <arg direction=\"out\" name=\"x\" type=\"i\" />"
"    <arg direction=\"out\" name=\"y\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetSize\">"
"    <arg direction=\"out\" name=\"width\" type=\"i\" />"
"    <arg direction=\"out\" name=\"height\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetLayer\">"
"    <arg direction=\"out\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GetMDIZOrder\">"
"    <arg direction=\"out\" type=\"n\" />"
"  </method>"
""
"  <method name=\"GrabFocus\">"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetAlpha\">"
"    <arg direction=\"out\" type=\"d\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Document = 
"<interface name=\"org.a11y.atspi.Document\" version=\"0.1.7\">"
""
"  <method name=\"GetLocale\">"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetAttributeValue\">"
"    <arg direction=\"in\" name=\"attributename\" type=\"s\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetAttributes\">"
"    <arg direction=\"out\" type=\"{ss}\" />"
"    "
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Hypertext = 
"<interface name=\"org.a11y.atspi.Hypertext\" version=\"0.1.7\">"
""
"  <method name=\"GetNLinks\">"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetLink\">"
"    <arg direction=\"in\" name=\"linkIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetLinkIndex\">"
"    <arg direction=\"in\" name=\"characterIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Hyperlink = 
"<interface name=\"org.a11y.atspi.Hyperlink\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"nAnchors\" type=\"n\" />"
""
"  <property access=\"read\" name=\"startIndex\" type=\"i\" />"
""
"  <property access=\"read\" name=\"endIndex\" type=\"i\" />"
""
"  <method name=\"GetObject\">"
"    <arg direction=\"in\" name=\"i\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetURI\">"
"    <arg direction=\"in\" name=\"i\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"IsValid\">"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Image = 
"<interface name=\"org.a11y.atspi.Image\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"imageDescription\" type=\"s\" />"
""
"  <property access=\"read\" name=\"imageLocale\" type=\"s\" />"
""
"  <method name=\"GetImageExtents\">"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"    <arg direction=\"out\" type=\"(iiii)\" />"
"    "
"  </method>"
""
"  <method name=\"GetImagePosition\">"
"    <arg direction=\"out\" name=\"x\" type=\"i\" />"
"    <arg direction=\"out\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GetImageSize\">"
"    <arg direction=\"out\" name=\"width\" type=\"i\" />"
"    <arg direction=\"out\" name=\"height\" type=\"i\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Selection = 
"<interface name=\"org.a11y.atspi.Selection\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"nSelectedChildren\" type=\"i\" />"
""
"  <method name=\"GetSelectedChild\">"
"    <arg direction=\"in\" name=\"selectedChildIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"SelectChild\">"
"    <arg direction=\"in\" name=\"childIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"DeselectSelectedChild\">"
"    <arg direction=\"in\" name=\"selectedChildIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"IsChildSelected\">"
"    <arg direction=\"in\" name=\"childIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"SelectAll\">"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"ClearSelection\">"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"deSelectChild\">"
"    <arg direction=\"in\" name=\"childIndex\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Table = 
"<interface name=\"org.a11y.atspi.Table\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"nRows\" type=\"i\" />"
""
"  <property access=\"read\" name=\"nColumns\" type=\"i\" />"
""
"  <property access=\"read\" name=\"caption\" type=\"(so)\">"
"    "
"  </property>"
""
"  <property access=\"read\" name=\"summary\" type=\"(so)\">"
"    "
"  </property>"
""
"  <property access=\"read\" name=\"nSelectedRows\" type=\"i\" />"
""
"  <property access=\"read\" name=\"nSelectedColumns\" type=\"i\" />"
""
"  <method name=\"GetAccessibleAt\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetIndexAt\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetRowAtIndex\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetColumnAtIndex\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetRowDescription\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetColumnDescription\">"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"GetRowExtentAt\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetColumnExtentAt\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetRowHeader\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetColumnHeader\">"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"(so)\" />"
"    "
"  </method>"
""
"  <method name=\"GetSelectedRows\">"
"    <arg direction=\"out\" type=\"ai\" />"
"    "
"  </method>"
""
"  <method name=\"GetSelectedColumns\">"
"    <arg direction=\"out\" type=\"ai\" />"
"    "
"  </method>"
""
"  <method name=\"IsRowSelected\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"IsColumnSelected\">"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"IsSelected\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"AddRowSelection\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"AddColumnSelection\">"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"RemoveRowSelection\">"
"    <arg direction=\"in\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"RemoveColumnSelection\">"
"    <arg direction=\"in\" name=\"column\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetRowColumnExtentsAtIndex\">"
"    <arg direction=\"in\" name=\"index\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"    <arg direction=\"out\" name=\"row\" type=\"i\" />"
"    <arg direction=\"out\" name=\"col\" type=\"i\" />"
"    <arg direction=\"out\" name=\"row_extents\" type=\"i\" />"
"    <arg direction=\"out\" name=\"col_extents\" type=\"i\" />"
"    <arg direction=\"out\" name=\"is_selected\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Text = 
"<interface name=\"org.a11y.atspi.Text\" version=\"0.1.7\">"
""
"  <property access=\"read\" name=\"characterCount\" type=\"i\" />"
""
"  <property access=\"read\" name=\"caretOffset\" type=\"i\" />"
""
"  <method name=\"GetText\">"
"    <arg direction=\"in\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endOffset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"s\" />"
"  </method>"
""
"  <method name=\"SetCaretOffset\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetTextBeforeOffset\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"s\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetTextAtOffset\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"s\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetTextAfterOffset\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"type\" type=\"u\" />"
"    <arg direction=\"out\" type=\"s\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetCharacterAtOffset\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetAttributeValue\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"attributeName\" type=\"s\" />"
"    <arg direction=\"out\" type=\"s\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"defined\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetAttributes\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"a{ss}\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"    "
"  </method>"
""
"  <method name=\"GetDefaultAttributes\">"
"    <arg direction=\"out\" type=\"a{ss}\" />"
"    "
"  </method>"
""
"  <method name=\"GetCharacterExtents\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"x\" type=\"i\" />"
"    <arg direction=\"out\" name=\"y\" type=\"i\" />"
"    <arg direction=\"out\" name=\"width\" type=\"i\" />"
"    <arg direction=\"out\" name=\"height\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GetOffsetAtPoint\">"
"    <arg direction=\"in\" name=\"x\" type=\"i\" />"
"    <arg direction=\"in\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetNSelections\">"
"    <arg direction=\"out\" type=\"i\" />"
"  </method>"
""
"  <method name=\"GetSelection\">"
"    <arg direction=\"in\" name=\"selectionNum\" type=\"i\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"  </method>"
""
"  <method name=\"AddSelection\">"
"    <arg direction=\"in\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endOffset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"RemoveSelection\">"
"    <arg direction=\"in\" name=\"selectionNum\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"SetSelection\">"
"    <arg direction=\"in\" name=\"selectionNum\" type=\"i\" />"
"    <arg direction=\"in\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endOffset\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"GetRangeExtents\">"
"    <arg direction=\"in\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"x\" type=\"i\" />"
"    <arg direction=\"out\" name=\"y\" type=\"i\" />"
"    <arg direction=\"out\" name=\"width\" type=\"i\" />"
"    <arg direction=\"out\" name=\"height\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GetBoundedRanges\">"
"    <arg direction=\"in\" name=\"x\" type=\"i\" />"
"    <arg direction=\"in\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"width\" type=\"i\" />"
"    <arg direction=\"in\" name=\"height\" type=\"i\" />"
"    <arg direction=\"in\" name=\"coordType\" type=\"u\" />"
"    <arg direction=\"in\" name=\"xClipType\" type=\"u\" />"
"    <arg direction=\"in\" name=\"yClipType\" type=\"u\" />"
"    <arg direction=\"out\" type=\"a(iisv)\" />"
"    "
"  </method>"
""
"  <method name=\"GetAttributeRun\">"
"    <arg direction=\"in\" name=\"offset\" type=\"i\" />"
"    <arg direction=\"in\" name=\"includeDefaults\" type=\"b\" />"
"    <arg direction=\"out\" type=\"a{ss}\" />"
"    <arg direction=\"out\" name=\"startOffset\" type=\"i\" />"
"    <arg direction=\"out\" name=\"endOffset\" type=\"i\" />"
"    "
"  </method>"
""
"  <method name=\"GetDefaultAttributeSet\">"
"    <arg direction=\"out\" type=\"as\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_EditableText = 
"<interface name=\"org.a11y.atspi.EditableText\" version=\"0.1.7\">"
""
"  <method name=\"SetTextContents\">"
"    <arg direction=\"in\" name=\"newContents\" type=\"s\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"InsertText\">"
"    <arg direction=\"in\" name=\"position\" type=\"i\" />"
"    <arg direction=\"in\" name=\"text\" type=\"s\" />"
"    <arg direction=\"in\" name=\"length\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"CopyText\">"
"    <arg direction=\"in\" name=\"startPos\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endPos\" type=\"i\" />"
"  </method>"
""
"  <method name=\"CutText\">"
"    <arg direction=\"in\" name=\"startPos\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endPos\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"DeleteText\">"
"    <arg direction=\"in\" name=\"startPos\" type=\"i\" />"
"    <arg direction=\"in\" name=\"endPos\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"PasteText\">"
"    <arg direction=\"in\" name=\"position\" type=\"i\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Cache = 
"<interface name=\"org.a11y.atspi.Cache\" version=\"0.1.7\">"
""
"  <method name=\"GetItems\">"
"    <arg direction=\"out\" name=\"nodes\" type=\"a((so)(so)a(so)assusau)\" />"
"    "
"  </method>"
""
"  <signal name=\"AddAccessible\">"
"    <arg name=\"nodeAdded\" type=\"((so)(so)a(so)assusau)\" />"
"    "
"  </signal>"
""
"  <signal name=\"RemoveAccessible\">"
"    <arg name=\"nodeRemoved\" type=\"(so)\" />"
"    "
"  </signal>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_Value = 
"<interface name=\"org.a11y.atspi.Value\" version=\"0.1.7\">"
""
"        <property access=\"read\" name=\"minimumValue\" type=\"d\" />"
""
"        <property access=\"read\" name=\"maximumValue\" type=\"d\" />"
""
"        <property access=\"read\" name=\"minimumIncrement\" type=\"d\" />"
""
"        <property access=\"readwrite\" name=\"currentValue\" type=\"d\" />"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_DeviceEventController = 
"<interface name=\"org.a11y.atspi.DeviceEventController\" version=\"0.1.7\">"
""
"  <method name=\"RegisterKeystrokeListener\">"
"    <arg direction=\"in\" name=\"listener\" type=\"o\" />"
"    <arg direction=\"in\" name=\"keys\" type=\"a(iisi)\">"
"      "
"    </arg>"
"    <arg direction=\"in\" name=\"mask\" type=\"u\" />"
"    <arg direction=\"in\" name=\"type\" type=\"au\">"
"      "
"    </arg>"
"    <arg direction=\"in\" name=\"mode\" type=\"(bbb)\">"
"      "
"    </arg>"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"DeregisterKeystrokeListener\">"
"    <arg direction=\"in\" name=\"listener\" type=\"o\" />"
"    <arg direction=\"in\" name=\"keys\" type=\"a(iisi)\">"
"      "
"    </arg>"
"    <arg direction=\"in\" name=\"mask\" type=\"u\" />"
"    <arg direction=\"in\" name=\"type\" type=\"u\" />"
"  </method>"
""
"  <method name=\"RegisterDeviceEventListener\">"
"    <arg direction=\"in\" name=\"listener\" type=\"o\" />"
"    <arg direction=\"in\" name=\"types\" type=\"u\" />"
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"  <method name=\"DeregisterDeviceEventListener\">"
"    <arg direction=\"in\" name=\"listener\" type=\"o\" />"
"    <arg direction=\"in\" name=\"types\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GenerateKeyboardEvent\">"
"    <arg direction=\"in\" name=\"keycode\" type=\"i\" />"
"    <arg direction=\"in\" name=\"keystring\" type=\"s\" />"
"    <arg direction=\"in\" name=\"type\" type=\"u\" />"
"  </method>"
""
"  <method name=\"GenerateMouseEvent\">"
"    <arg direction=\"in\" name=\"x\" type=\"i\" />"
"    <arg direction=\"in\" name=\"y\" type=\"i\" />"
"    <arg direction=\"in\" name=\"eventName\" type=\"s\" />"
"  </method>"
""
"  <method name=\"NotifyListenersSync\">"
"    <arg direction=\"in\" name=\"event\" type=\"(uinnisb)\" />"
"    <arg direction=\"out\" type=\"b\" />"
"    "
"  </method>"
""
"  <method name=\"NotifyListenersAsync\">"
"    <arg direction=\"in\" name=\"event\" type=\"(uinnisb)\" />"
"    "
"  </method>"
""
"</interface>"
"";

const char *spi_org_a11y_atspi_DeviceEventListener = 
"<interface name=\"org.a11y.atspi.DeviceEventListener\" version=\"0.1.7\">"
""
"  <method name=\"NotifyEvent\">"
"    <arg direction=\"in\" name=\"event\" type=\"(uinnisb)\" />"
"    "
"    <arg direction=\"out\" type=\"b\" />"
"  </method>"
""
"</interface>"
"";

