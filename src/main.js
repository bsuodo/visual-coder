let workspace = document.getElementById("workspace");

let mouse_track = {
    mouse_origin_x: 0,
    mouse_origin_y: 0,

    mouse_current_x: 0,
    mouse_current_y: 0,

    workspace_dragged: false,
}

document.addEventListener("mousedown", (info) => {
    mouse_track = {
        ...mouse_track,
        mouse_origin_x: info.clientX,
        mouse_origin_y: info.clientY,
    };
});

document.addEventListener("mousemove", (info) => {
    mouse_track = {
        ...mouse_track,
        mouse_current_x: info.clientX,
        mouse_current_y: info.clientY,
    };
});

workspace.addEventListener("mousedown", (info) => { mouse_track.workspace_dragged = true; });
workspace.addEventListener("mouseup", (info) => { mouse_track.workspace_dragged = false; });


function MainLoop()
{
    if (mouse_track.workspace_dragged)
    {
        let workspace_pos_x = parseInt(getComputedStyle(workspace).backgroundPositionX);
        let workspace_pos_y = parseInt(getComputedStyle(workspace).backgroundPositionY);

        let mouse_delta_x = (mouse_track.mouse_current_x - mouse_track.mouse_origin_x) / 6;
        let mouse_delta_y = (mouse_track.mouse_current_y - mouse_track.mouse_origin_y) / 6;

        workspace_pos_x -= mouse_delta_x;
        workspace_pos_y -= mouse_delta_y;

        mouse_track.mouse_origin_x += mouse_delta_x;
        mouse_track.mouse_origin_y += mouse_delta_y;

        workspace.style.backgroundPositionX = workspace_pos_x + "px";
        workspace.style.backgroundPositionY = workspace_pos_y + "px";
    }

    requestAnimationFrame(MainLoop);
}

requestAnimationFrame(MainLoop);