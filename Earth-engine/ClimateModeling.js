/**************************************************************
 * Aura Climate Explorer v1
 * NASA NEX-DCP30 Climate Projection Explorer
 * Author: Seriki Yakub (KUBU LEE)
 **************************************************************/

// ---------------------------------------------------------------------
// Region of Interest
// ---------------------------------------------------------------------

var roi = ee.FeatureCollection('USGS/WBD/2017/HUC06')
    .filter(ee.Filter.eq('huc6', '180400'));

Map.centerObject(roi, 7);

// ---------------------------------------------------------------------
// Dataset
// ---------------------------------------------------------------------

var dataset = ee.ImageCollection('NASA/NEX-DCP30_ENSEMBLE_STATS');

// ---------------------------------------------------------------------
// UI
// ---------------------------------------------------------------------

var panel = ui.Panel({
  style: {
    width: '320px',
    padding: '10px'
  }
});

panel.add(ui.Label({
  value: 'Aura Climate Explorer',
  style: {
    fontWeight: 'bold',
    fontSize: '22px'
  }
}));

panel.add(ui.Label('NASA NEX-DCP30 Climate Projections'));


// ---------------------------------------------------------------------
// Scenario Selector
// ---------------------------------------------------------------------

var scenarioSelect = ui.Select({
  items: ['rcp26','rcp45','rcp60','rcp85'],
  value: 'rcp26'
});

panel.add(ui.Label('Scenario'));
panel.add(scenarioSelect);

// ---------------------------------------------------------------------
// Variable
// ---------------------------------------------------------------------

var variableSelect = ui.Select({
  items: [
    'tasmax_median',
    'tasmax_quartile25',
    'tasmax_quartile75'
  ],
  value: 'tasmax_median'
});

panel.add(ui.Label('Variable'));
panel.add(variableSelect);

// ---------------------------------------------------------------------
// Month
// ---------------------------------------------------------------------

var months = [
'January','February','March','April',
'May','June','July','August',
'September','October','November','December'
];

var monthSelect = ui.Select({
  items: months,
  value: 'July'
});

panel.add(ui.Label('Month'));
panel.add(monthSelect);

// ---------------------------------------------------------------------
// Year
// ---------------------------------------------------------------------

var years = [];

for(var y=2010;y<=2100;y++){
    years.push(String(y));
}

var yearSelect = ui.Select({
    items: years,
    value:'2050'
});

panel.add(ui.Label('Year'));
panel.add(yearSelect);

// ---------------------------------------------------------------------
// Palette
// ---------------------------------------------------------------------

var palette = [
'000004',
'320A5A',
'781B6C',
'BB3654',
'EC6824',
'FBB41A',
'FCFFA4'
];

var vis = {
    min:17,
    max:40,
    palette:palette
};

// ---------------------------------------------------------------------
// Update Function
// ---------------------------------------------------------------------

function updateMap(){

    Map.layers().reset();

    var month =
        months.indexOf(monthSelect.getValue()) + 1;

    var year =
        ee.Number.parse(yearSelect.getValue());

    var start =
        ee.Date.fromYMD(year,month,1);

    var end =
        start.advance(1,'month');

    var image = dataset
        .filter(ee.Filter.eq(
            'scenario',
            scenarioSelect.getValue()))
        .filterDate(start,end)
        .first();

    image = image.subtract(273.15);

    Map.addLayer(
        image.select(variableSelect.getValue()),
        vis,
        scenarioSelect.getValue() +
        " " +
        yearSelect.getValue()
    );

    Map.addLayer(
        roi,
        {color:'white'},
        'Watershed'
    );

}

var refresh = ui.Button({
    label:'Update Map',
    onClick:updateMap
});

panel.add(refresh);

ui.root.insert(0,panel);

updateMap();
