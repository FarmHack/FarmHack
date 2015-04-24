$(function() {

  App.Views.SearchForm = Backbone.View.extend({

    template: ' \
            <div class="col-sm-9"> \
              <div class="search-form"> \ 
                <div class="simple"> \ 
                  <div class="input-group input-group-lg"> \ 
                    <input type="text" class="form-control" placeholder="Search for Hacks..."> \ 
                    <span class="input-group-btn"> \ 
                      <button class="btn btn-default" type="button"><span class="glyphicon glyphicon-search" aria-hidden="true"></span></button> \ 
                    </span> \ 
                  </div><!-- /input-group --> \ 
                </div><!-- /search-form-simple --> \ 
                <div style="opacity: 1;" class="advanced form-horizontal"> \ 
                  <div class="form-control-wrapper"> \ 
                    <select class="form-control input-lg" id="hack-type"> \ 
                      <option>Topic</option> \ 
                      <option>---</option> \ 
                      <option value"1"="">All</option> \ 
                      <option value="79">"Smart Farm" tools</option><option value="78">Crop storage</option><option value="14">Energy</option><option value="73">Fencing and livestock management</option><option value="15">Harvesting</option><option value="72">Irrigation and Water Management</option><option value="75">Planting</option><option value="98">Pollinators / Honey</option><option value="16">Post Harvest</option><option value="81">Season extension</option><option value="13">Soil management</option><option value="80">Universal farm infrastructure/farm shop</option><option value="12">Water</option> \ 
                    </select> \ 
                  </div> \ 
                  <div class="form-control-wrapper"> \ 
                    <select class="form-control input-lg" id="hack-type"> \ 
                      <option>Documentation Level</option> \ 
                      <option>---</option> \ 
                      <option value"1"="">Idea</option> \ 
                      <option value"1"="">Just a picture</option> \ 
                      <option>Includes a tutorial</option> \ 
                      <option>Includes more than tutorial</option> \ 
                    </select> \ 
                  </div> \ 
                  <div class="form-control-wrapper"> \ 
                    <div class="checkbox"> \ 
                      <label> \ 
                        <input type="checkbox" value=""> \ 
                        Also search comments on Hacks \ 
                      </label> \ 
                    </div> \ 
                  </div> \ 
                  <div class="submit"> \ 
                    <button type="button" class="btn btn-primary btn-lg">Submit search</button> \ 
                  </div> \ 
                </div> \ 
              </div><!-- /search-form --> \ 
            </div> 
            ',

    render: function() {
      this.$el.append(this.template)
    }

  })

})
